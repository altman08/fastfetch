#include "logo.h"
#include "logo_builtin.h"
#include "common/color.h"

const FFlogo ffLogoUnknown = {
    .names = { "unknown" },
    .lines = FASTFETCH_DATATEXT_LOGO_UNKNOWN,
    .colors = {
        FF_COLOR_FG_DEFAULT,
    },
};

static const FFlogo A[] = {
    // Alpine
    {
        .names = { "Alpine" },
        .lines = FASTFETCH_DATATEXT_LOGO_ALPINE,
        .colors = {
            FF_COLOR_FG_BLUE,
        },
        .colorKeys = FF_COLOR_FG_MAGENTA,
        .colorTitle = FF_COLOR_FG_BLUE,
    },
    // Arch
    {
        .names = { "arch", "archmerge" },
        .lines = FASTFETCH_DATATEXT_LOGO_ARCH,
        .colors = {
            FF_COLOR_FG_CYAN,
            FF_COLOR_FG_CYAN,
        },
    },
    // LAST
    {},
};

static const FFlogo B[] = {
    // LAST
    {},
};

static const FFlogo C[] = {
    // CentOS
    {
        .names = { "CentOS" },
        .lines = FASTFETCH_DATATEXT_LOGO_CENTOS,
        .colors = {
            FF_COLOR_FG_YELLOW,
            FF_COLOR_FG_GREEN,
            FF_COLOR_FG_BLUE,
            FF_COLOR_FG_MAGENTA,
            FF_COLOR_FG_WHITE,
        },
        .colorKeys = FF_COLOR_FG_GREEN,
        .colorTitle = FF_COLOR_FG_YELLOW,
    },
    // LAST
    {},
};

static const FFlogo D[] = {
    // Debian
    {
        .names = { "Debian" },
        .lines = FASTFETCH_DATATEXT_LOGO_DEBIAN,
        .colors = {
            FF_COLOR_FG_RED,
            FF_COLOR_FG_WHITE,
        },
        .colorKeys = FF_COLOR_FG_RED,
        .colorTitle = FF_COLOR_FG_RED,
    },
    // LAST
    {},
};

static const FFlogo E[] = {
    // LAST
    {},
};

static const FFlogo F[] = {
    // Fastfetch
    {
        .names = { "Fastfetch", "FF" },
        .lines = FASTFETCH_DATATEXT_LOGO_FASTFETCH,
        .colors = {
            FF_COLOR_FG_BLUE,
            FF_COLOR_FG_RED,
            FF_COLOR_FG_YELLOW,
            FF_COLOR_FG_GREEN,
            FF_COLOR_FG_DEFAULT,
            FF_COLOR_FG_MAGENTA,
            FF_COLOR_FG_CYAN,
        },
        .colorKeys = FF_COLOR_FG_BLUE,
        .colorTitle = FF_COLOR_FG_YELLOW,
    },
    // Fedora
    {
        .names = { "Fedora" },
        .lines = FASTFETCH_DATATEXT_LOGO_FEDORA,
        .colors = {
            FF_COLOR_FG_BLUE,
            FF_COLOR_FG_WHITE,
        },
        .colorKeys = FF_COLOR_FG_BLUE,
        .colorTitle = FF_COLOR_FG_DEFAULT,
    },
    // LAST
    {},
};

static const FFlogo G[] = {
    // LAST
    {},
};

static const FFlogo H[] = {
    // LAST
    {},
};

static const FFlogo I[] = {
    // LAST
    {},
};

static const FFlogo J[] = {
    // LAST
    {},
};

static const FFlogo K[] = {
    // Kali
    {
        .names = { "Kali" },
        .lines = FASTFETCH_DATATEXT_LOGO_KALI,
        .colors = {
            FF_COLOR_FG_BLUE,
            FF_COLOR_FG_LIGHT_BLACK,
        },
        .colorKeys = FF_COLOR_FG_BLUE,
        .colorTitle = FF_COLOR_FG_DEFAULT,
    },
    // LAST
    {},
};

static const FFlogo L[] = {
    // Linux
    {
        .names = { "Linux", "linux-generic" },
        .lines = FASTFETCH_DATATEXT_LOGO_LINUX,
        .colors = {
            FF_COLOR_FG_WHITE,
            FF_COLOR_FG_LIGHT_BLACK,
            FF_COLOR_FG_YELLOW,
        },
        .colorKeys = FF_COLOR_FG_DEFAULT,
        .colorTitle = FF_COLOR_FG_YELLOW,
    },
    // LAST
    {},
};

static const FFlogo M[] = {
    // Merlin
    {
        .names = {"Merlin", "merlin"},
        .lines = FASTFETCH_DATATEXT_LOGO_MERLIN,
        .colors = {
            FF_COLOR_FG_BLUE,
        },
        .colorKeys = FF_COLOR_FG_BLUE,
        .colorTitle = FF_COLOR_FG_DEFAULT,
    },
    // LAST
    {},
};

static const FFlogo N[] = {
    // LAST
    {},
};

static const FFlogo O[] = {
    // OpenWrt
    {
        .names = { "openwrt" },
        .lines = FASTFETCH_DATATEXT_LOGO_OPENWRT,
        .colors = {
            FF_COLOR_FG_BLUE,
        },
        .colorKeys = FF_COLOR_FG_BLUE,
        .colorTitle = FF_COLOR_FG_DEFAULT,
    },
    // LAST
    {},
};

static const FFlogo P[] = {
    // LAST
    {},
};

static const FFlogo Q[] = {
    // LAST
    {},
};

static const FFlogo R[] = {
    // LAST
    {},
};

static const FFlogo S[] = {
    // LAST
    {},
};

static const FFlogo T[] = {
    // LAST
    {},
};

static const FFlogo U[] = {
    // Ubuntu
    {
        .names = { "ubuntu", "ubuntu-linux" },
        .lines = FASTFETCH_DATATEXT_LOGO_UBUNTU,
        .colors = {
            FF_COLOR_FG_RED,
            FF_COLOR_FG_RED,
        },
    },
    // LAST
    {},
};

static const FFlogo V[] = {
    // LAST
    {},
};

static const FFlogo W[] = {
    // LAST
    {},
};

static const FFlogo X[] = {
    // LAST
    {},
};

static const FFlogo Y[] = {
    // LAST
    {},
};

static const FFlogo Z[] = {
    // LAST
    {},
};

const FFlogo* ffLogoBuiltins[] = {
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
};
