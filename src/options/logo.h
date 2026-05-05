#pragma once

#include "common/ffdata.h"

#define FASTFETCH_LOGO_MAX_NAMES 9
#define FASTFETCH_LOGO_MAX_COLORS 9 // two digits would make parsing much more complicated (index 1 - 9)

typedef enum FF_A_PACKED FFLogoType {
    FF_LOGO_TYPE_AUTO,               // if something is given, first try builtin, then file. Otherwise detect logo
    FF_LOGO_TYPE_BUILTIN,            // builtin ascii art
    FF_LOGO_TYPE_SMALL,              // builtin ascii art, small version
    FF_LOGO_TYPE_FILE,               // text file, printed with color code replacement
    FF_LOGO_TYPE_FILE_RAW,           // text file, printed as is
    FF_LOGO_TYPE_DATA,               // text data, printed with color code replacement
    FF_LOGO_TYPE_DATA_RAW,           // text data, printed as is
    FF_LOGO_TYPE_COMMAND_RAW,        // command to generate text data, printed as is
    FF_LOGO_TYPE_NONE,               // `--logo none`, but still applies colors to the system information output (unless `--pipe` is set)
} FFLogoType;

typedef enum FF_A_PACKED FFLogoPosition {
    FF_LOGO_POSITION_LEFT,
    FF_LOGO_POSITION_TOP,
    FF_LOGO_POSITION_RIGHT,
} FFLogoPosition;

typedef struct FFOptionsLogo {
    FFstrbuf source;
    FFLogoType type;
    FFLogoPosition position;
    FFstrbuf colors[FASTFETCH_LOGO_MAX_COLORS];
    uint32_t width;
    uint32_t height;
    uint32_t paddingTop;
    uint32_t paddingLeft;
    uint32_t paddingRight;
    bool printRemaining;
    bool preserveAspectRatio;
    bool recache;
} FFOptionsLogo;

void ffOptionsInitLogo(FFOptionsLogo* options);
bool ffOptionsParseLogoCommandLine(FFOptionsLogo* options, const char* key, const char* value);
void ffOptionsDestroyLogo(FFOptionsLogo* options);
const char* ffOptionsParseLogoJsonConfig(FFOptionsLogo* options, yyjson_val* root);
void ffOptionsGenerateLogoJsonConfig(FFdata* data, FFOptionsLogo* options);
