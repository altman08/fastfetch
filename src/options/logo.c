#include "logo/logo.h"

#include "common/jsonconfig.h"
#include "common/stringUtils.h"

void ffOptionsInitLogo(FFOptionsLogo* options) {
    ffStrbufInit(&options->source);
    options->type = FF_LOGO_TYPE_AUTO;
    for (uint8_t i = 0; i < (uint8_t) FASTFETCH_LOGO_MAX_COLORS; ++i) {
        ffStrbufInit(&options->colors[i]);
    }
    options->width = 0;
    options->height = 0; // preserve aspect ratio
    options->paddingTop = 0;
    options->paddingLeft = 0;
    options->paddingRight = 4;
    options->printRemaining = true;
    options->preserveAspectRatio = false;
    options->recache = false;
    options->position = FF_LOGO_POSITION_LEFT;
}

bool ffOptionsParseLogoCommandLine(FFOptionsLogo* options, const char* key, const char* value) {
    if (ffStrEqualsIgnCase(key, "-l")) {
        goto logoType;
    }

    const char* subKey = ffOptionTestPrefix(key, "logo");
    if (subKey) {
        if (subKey[0] == '\0') {
        logoType:
            if (value == NULL) {
                fprintf(stderr, "Error: usage: %s <none|small|logo-source>\n", key);
                exit(477);
            }
            // this is usually wanted when disabling logo
            if (ffStrEqualsIgnCase(value, "none")) {
                options->type = FF_LOGO_TYPE_NONE;
            } else if (ffStrEqualsIgnCase(value, "small")) {
                options->type = FF_LOGO_TYPE_SMALL;
            } else {
                ffOptionParseString(key, value, &options->source);
            }
        } else if (ffStrEqualsIgnCase(subKey, "type")) {
            options->type = (FFLogoType) ffOptionParseEnum(key, value, (FFKeyValuePair[]) {
                                                                           { "auto", FF_LOGO_TYPE_AUTO },
                                                                           { "builtin", FF_LOGO_TYPE_BUILTIN },
                                                                           { "small", FF_LOGO_TYPE_SMALL },
                                                                           { "file", FF_LOGO_TYPE_FILE },
                                                                           { "file-raw", FF_LOGO_TYPE_FILE_RAW },
                                                                           { "data", FF_LOGO_TYPE_DATA },
                                                                           { "data-raw", FF_LOGO_TYPE_DATA_RAW },
                                                                           { "command-raw", FF_LOGO_TYPE_COMMAND_RAW },
                                                                           { "none", FF_LOGO_TYPE_NONE },
                                                                           {},
                                                                       });
        } else if (ffStrStartsWithIgnCase(subKey, "color-") && subKey[6] != '\0' && subKey[7] == '\0') // matches "--logo-color-*"
        {
            // Map the number to an array index, so that '1' -> 0, '2' -> 1, etc.
            int index = (int) subKey[6] - '0' - 1;

            // Match only --logo-color-[1-9]
            if (index < 0 || index >= FASTFETCH_LOGO_MAX_COLORS) {
                fprintf(stderr, "Error: invalid --color-[1-9] index: %c\n", key[13]);
                exit(472);
            }
            if (value == NULL) {
                fprintf(stderr, "Error: usage: %s <str>\n", key);
                exit(477);
            }
            ffOptionParseColor(value, &options->colors[index]);
        } else if (ffStrEqualsIgnCase(subKey, "width")) {
            options->width = ffOptionParseUInt32(key, value);
        } else if (ffStrEqualsIgnCase(subKey, "height")) {
            options->height = ffOptionParseUInt32(key, value);
        } else if (ffStrEqualsIgnCase(subKey, "padding")) {
            uint32_t padding = ffOptionParseUInt32(key, value);
            options->paddingLeft = padding;
            options->paddingRight = padding;
        } else if (ffStrEqualsIgnCase(subKey, "padding-top")) {
            options->paddingTop = ffOptionParseUInt32(key, value);
        } else if (ffStrEqualsIgnCase(subKey, "padding-left")) {
            options->paddingLeft = ffOptionParseUInt32(key, value);
        } else if (ffStrEqualsIgnCase(subKey, "padding-right")) {
            options->paddingRight = ffOptionParseUInt32(key, value);
        } else if (ffStrEqualsIgnCase(subKey, "print-remaining")) {
            options->printRemaining = ffOptionParseBoolean(value);
        } else if (ffStrEqualsIgnCase(subKey, "preserve-aspect-ratio")) {
            options->preserveAspectRatio = ffOptionParseBoolean(value);
        } else if (ffStrEqualsIgnCase(subKey, "recache")) {
            options->recache = ffOptionParseBoolean(value);
        } else if (ffStrEqualsIgnCase(subKey, "separate")) {
            fputs("--logo-separate has been renamed to --logo-position\n", stderr);
            exit(477);
        } else if (ffStrEqualsIgnCase(subKey, "position")) {
            options->position = (FFLogoPosition) ffOptionParseEnum(key, value, (FFKeyValuePair[]) {
                                                                                   { "left", FF_LOGO_POSITION_LEFT },
                                                                                   { "right", FF_LOGO_POSITION_RIGHT },
                                                                                   { "top", FF_LOGO_POSITION_TOP },
                                                                                   {},
                                                                               });
        } else {
            return false;
        }
    } else if ((subKey = ffOptionTestPrefix(key, "file"))) {
        if (subKey[0] == '\0') {
            ffOptionParseString(key, value, &options->source);
            options->type = FF_LOGO_TYPE_FILE;
        } else if (ffStrEqualsIgnCase(subKey, "raw")) {
            ffOptionParseString(key, value, &options->source);
            options->type = FF_LOGO_TYPE_FILE_RAW;
        } else {
            return false;
        }
    } else if ((subKey = ffOptionTestPrefix(key, "data"))) {
        if (subKey[0] == '\0') {
            ffOptionParseString(key, value, &options->source);
            options->type = FF_LOGO_TYPE_DATA;
        } else if (ffStrEqualsIgnCase(subKey, "raw")) {
            ffOptionParseString(key, value, &options->source);
            options->type = FF_LOGO_TYPE_DATA_RAW;
        } else {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

void ffOptionsDestroyLogo(FFOptionsLogo* options) {
    ffStrbufDestroy(&options->source);
    for (uint8_t i = 0; i < (uint8_t) FASTFETCH_LOGO_MAX_COLORS; ++i) {
        ffStrbufDestroy(&options->colors[i]);
    }
}

const char* ffOptionsParseLogoJsonConfig(FFOptionsLogo* options, yyjson_val* root) {
    yyjson_val* object = yyjson_obj_get(root, "logo");
    if (!object) {
        return NULL;
    }
    if (yyjson_is_null(object)) {
        options->type = FF_LOGO_TYPE_NONE;
        options->paddingTop = 0;
        options->paddingRight = 0;
        options->paddingLeft = 0;
        return NULL;
    }

    if (yyjson_is_str(object)) {
        ffStrbufSetJsonVal(&options->source, object);
        return NULL;
    }

    if (!yyjson_is_obj(object)) {
        return "Property 'logo' must be an object";
    }

    yyjson_val *key, *val;
    size_t idx, max;
    yyjson_obj_foreach (object, idx, max, key, val) {
        if (unsafe_yyjson_equals_str(key, "type")) {
            int value;
            const char* error = ffJsonConfigParseEnum(val, &value, (FFKeyValuePair[]) {
                                                                       { "auto", FF_LOGO_TYPE_AUTO },
                                                                       { "builtin", FF_LOGO_TYPE_BUILTIN },
                                                                       { "small", FF_LOGO_TYPE_SMALL },
                                                                       { "file", FF_LOGO_TYPE_FILE },
                                                                       { "file-raw", FF_LOGO_TYPE_FILE_RAW },
                                                                       { "data", FF_LOGO_TYPE_DATA },
                                                                       { "data-raw", FF_LOGO_TYPE_DATA_RAW },
                                                                       { "command-raw", FF_LOGO_TYPE_COMMAND_RAW },
                                                                       { "none", FF_LOGO_TYPE_NONE },
                                                                       {},
                                                                   });

            if (error) {
                return error;
            }
            options->type = (FFLogoType) value;
            continue;
        } else if (unsafe_yyjson_equals_str(key, "source")) {
            ffStrbufSetJsonVal(&options->source, val);
            continue;
        } else if (unsafe_yyjson_equals_str(key, "color")) {
            if (!yyjson_is_obj(val)) {
                return "Property 'color' must be an object";
            }

            yyjson_val *keyc, *valc;
            size_t idxc, maxc;
            yyjson_obj_foreach (val, idxc, maxc, keyc, valc) {
                uint32_t index = (uint32_t) strtoul(unsafe_yyjson_get_str(keyc), NULL, 10);
                if (index < 1 || index > FASTFETCH_LOGO_MAX_COLORS) {
                    return "Keys of property 'color' must be a number between 1 to 9";
                }

                ffOptionParseColor(yyjson_get_str(valc), &options->colors[index - 1]);
            }
            continue;
        } else if (unsafe_yyjson_equals_str(key, "width")) {
            if (yyjson_is_null(val)) {
                options->width = 0;
            } else {
                uint32_t value = (uint32_t) yyjson_get_uint(val);
                if (value == 0) {
                    return "Logo width must be a positive integer";
                }
                options->width = value;
            }
            continue;
        } else if (unsafe_yyjson_equals_str(key, "height")) {
            if (yyjson_is_null(val)) {
                options->height = 0;
            } else {
                uint32_t value = (uint32_t) yyjson_get_uint(val);
                if (value == 0) {
                    return "Logo height must be a positive integer";
                }
                options->height = value;
            }
            continue;
        } else if (unsafe_yyjson_equals_str(key, "padding")) {
            if (!yyjson_is_obj(val)) {
                return "Logo padding must be an object";
            }

#define FF_PARSE_PADDING_POSITON(pos, paddingPos)                   \
    yyjson_val* pos = yyjson_obj_get(val, #pos);                    \
    if (pos) {                                                      \
        if (!yyjson_is_uint(pos))                                   \
            return "Logo padding values must be positive integers"; \
        options->paddingPos = (uint32_t) yyjson_get_uint(pos);      \
    }
            FF_PARSE_PADDING_POSITON(left, paddingLeft);
            FF_PARSE_PADDING_POSITON(top, paddingTop);
            FF_PARSE_PADDING_POSITON(right, paddingRight);
#undef FF_PARSE_PADDING_POSITON
            continue;
        } else if (unsafe_yyjson_equals_str(key, "printRemaining")) {
            options->printRemaining = yyjson_get_bool(val);
            continue;
        } else if (unsafe_yyjson_equals_str(key, "preserveAspectRatio")) {
            options->preserveAspectRatio = yyjson_get_bool(val);
            continue;
        } else if (unsafe_yyjson_equals_str(key, "recache")) {
            options->recache = yyjson_get_bool(val);
            continue;
        } else if (unsafe_yyjson_equals_str(key, "position")) {
            int value;
            const char* error = ffJsonConfigParseEnum(val, &value, (FFKeyValuePair[]) {
                                                                       { "left", FF_LOGO_POSITION_LEFT },
                                                                       { "top", FF_LOGO_POSITION_TOP },
                                                                       { "right", FF_LOGO_POSITION_RIGHT },
                                                                       {},
                                                                   });

            if (error) {
                return error;
            }
            options->position = (FFLogoPosition) value;
            continue;
        } else {
            return "Unknown logo key";
        }
    }

    return NULL;
}

void ffOptionsGenerateLogoJsonConfig(FFdata* data, FFOptionsLogo* options) {
    yyjson_mut_doc* doc = data->resultDoc;
    yyjson_mut_val* obj = yyjson_mut_obj(doc);

    switch (options->type) {
        case FF_LOGO_TYPE_NONE:
            yyjson_mut_obj_add_null(doc, doc->root, "logo");
            return;
        case FF_LOGO_TYPE_BUILTIN:
            yyjson_mut_obj_add_str(doc, obj, "type", "builtin");
            break;
        case FF_LOGO_TYPE_SMALL:
            yyjson_mut_obj_add_str(doc, obj, "type", "small");
            break;
        case FF_LOGO_TYPE_FILE:
            yyjson_mut_obj_add_str(doc, obj, "type", "file");
            break;
        case FF_LOGO_TYPE_FILE_RAW:
            yyjson_mut_obj_add_str(doc, obj, "type", "file-raw");
            break;
        case FF_LOGO_TYPE_DATA:
            yyjson_mut_obj_add_str(doc, obj, "type", "data");
            break;
        case FF_LOGO_TYPE_DATA_RAW:
            yyjson_mut_obj_add_str(doc, obj, "type", "data-raw");
            break;
        case FF_LOGO_TYPE_COMMAND_RAW:
            yyjson_mut_obj_add_str(doc, obj, "type", "command-raw");
            break;
        default:
            yyjson_mut_obj_add_str(doc, obj, "type", "auto");
            break;
    }

    yyjson_mut_obj_add_str(doc, obj, "source", options->source.chars);

    {
        yyjson_mut_val* color = yyjson_mut_obj(doc);
        for (int i = 0; i < FASTFETCH_LOGO_MAX_COLORS; i++) {
            char c = (char) ('1' + i);
            yyjson_mut_obj_add(color, yyjson_mut_strncpy(doc, &c, 1), yyjson_mut_strbuf(doc, &options->colors[i]));
        }
        yyjson_mut_obj_add_val(doc, obj, "color", color);
    }

    if (options->width == 0) {
        yyjson_mut_obj_add_null(doc, obj, "width");
    } else {
        yyjson_mut_obj_add_uint(doc, obj, "width", options->width);
    }

    if (options->height == 0) {
        yyjson_mut_obj_add_null(doc, obj, "height");
    } else {
        yyjson_mut_obj_add_uint(doc, obj, "height", options->height);
    }

    {
        yyjson_mut_val* padding = yyjson_mut_obj_add_obj(doc, obj, "padding");
        yyjson_mut_obj_add_uint(doc, padding, "top", options->paddingTop);
        yyjson_mut_obj_add_uint(doc, padding, "left", options->paddingLeft);
        yyjson_mut_obj_add_uint(doc, padding, "right", options->paddingRight);
    }

    yyjson_mut_obj_add_bool(doc, obj, "printRemaining", options->printRemaining);

    yyjson_mut_obj_add_bool(doc, obj, "preserveAspectRatio", options->preserveAspectRatio);

    yyjson_mut_obj_add_bool(doc, obj, "recache", options->recache);

    yyjson_mut_obj_add_str(doc, obj, "position", ((const char*[]) {
                                                     "left",
                                                     "top",
                                                     "right",
                                                 })[options->position]);

    yyjson_mut_obj_add_val(doc, doc->root, "logo", obj);
}
