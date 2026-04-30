#include "modules/modules.h"

// Note:
// FF_MODULE_DISABLE_<module> only controls if the module is registered,
// the module code itself is still compiled.
// We rely `LTO` to remove the unused code (only enabled in Release mode)

static FFModuleBaseInfo* A[] = {
    NULL,
};

static FFModuleBaseInfo* B[] = {
#if !FF_MODULE_DISABLE_BOARD
    &ffBoardModuleInfo,
#endif
#if !FF_MODULE_DISABLE_BREAK
    &ffBreakModuleInfo,
#endif
#if !FF_MODULE_DISABLE_BTRFS
    &ffBtrfsModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* C[] = {
#if !FF_MODULE_DISABLE_COMMAND
    &ffCommandModuleInfo,
#endif
#if !FF_MODULE_DISABLE_COLORS
    &ffColorsModuleInfo,
#endif
#if !FF_MODULE_DISABLE_CPU
    &ffCPUModuleInfo,
#endif
#if !FF_MODULE_DISABLE_CPUCACHE
    &ffCPUCacheModuleInfo,
#endif
#if !FF_MODULE_DISABLE_CPUUSAGE
    &ffCPUUsageModuleInfo,
#endif
#if !FF_MODULE_DISABLE_CUSTOM
    &ffCustomModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* D[] = {
#if !FF_MODULE_DISABLE_DATETIME
    &ffDateTimeModuleInfo,
#endif
#if !FF_MODULE_DISABLE_DISPLAY
    &ffDisplayModuleInfo,
#endif
#if !FF_MODULE_DISABLE_DISK
    &ffDiskModuleInfo,
#endif
#if !FF_MODULE_DISABLE_DISKIO
    &ffDiskIOModuleInfo,
#endif
#if !FF_MODULE_DISABLE_DNS
    &ffDNSModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* E[] = {
#if !FF_MODULE_DISABLE_EDITOR
    &ffEditorModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* F[] = {
    NULL,
};

static FFModuleBaseInfo* G[] = {
    NULL,
};

static FFModuleBaseInfo* H[] = {
#if !FF_MODULE_DISABLE_HOST
    &ffHostModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* I[] = {
#if !FF_MODULE_DISABLE_ICONS
    &ffIconsModuleInfo,
#endif
#if !FF_MODULE_DISABLE_INITSYSTEM
    &ffInitSystemModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* J[] = {
    NULL,
};

static FFModuleBaseInfo* K[] = {
#if !FF_MODULE_DISABLE_KERNEL
    &ffKernelModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* L[] = {
#if !FF_MODULE_DISABLE_LOADAVG
    &ffLoadavgModuleInfo,
#endif
#if !FF_MODULE_DISABLE_LOCALE
    &ffLocaleModuleInfo,
#endif
#if !FF_MODULE_DISABLE_LOCALIP
    &ffLocalIPModuleInfo,
#endif
#if !FF_MODULE_DISABLE_LOGO
    &ffLogoModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* M[] = {
#if !FF_MODULE_DISABLE_MEMORY
    &ffMemoryModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* N[] = {
#if !FF_MODULE_DISABLE_NETIO
    &ffNetIOModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* O[] = {
#if !FF_MODULE_DISABLE_OS
    &ffOSModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* P[] = {
#if !FF_MODULE_DISABLE_PACKAGES
    &ffPackagesModuleInfo,
#endif
#if !FF_MODULE_DISABLE_PHYSICALDISK
    &ffPhysicalDiskModuleInfo,
#endif
#if !FF_MODULE_DISABLE_PHYSICALMEMORY
    &ffPhysicalMemoryModuleInfo,
#endif
#if !FF_MODULE_DISABLE_PROCESSES
    &ffProcessesModuleInfo,
#endif
#if !FF_MODULE_DISABLE_PUBLICIP
    &ffPublicIPModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* Q[] = {
    NULL,
};

static FFModuleBaseInfo* R[] = {
    NULL,
};

static FFModuleBaseInfo* S[] = {
#if !FF_MODULE_DISABLE_SEPARATOR
    &ffSeparatorModuleInfo,
#endif
#if !FF_MODULE_DISABLE_SHELL
    &ffShellModuleInfo,
#endif
#if !FF_MODULE_DISABLE_SWAP
    &ffSwapModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* T[] = {
#if !FF_MODULE_DISABLE_TERMINAL
    &ffTerminalModuleInfo,
#endif
#if !FF_MODULE_DISABLE_TERMINALSIZE
    &ffTerminalSizeModuleInfo,
#endif
#if !FF_MODULE_DISABLE_TITLE
    &ffTitleModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* U[] = {
#if !FF_MODULE_DISABLE_UPTIME
    &ffUptimeModuleInfo,
#endif
#if !FF_MODULE_DISABLE_USERS
    &ffUsersModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* V[] = {
#if !FF_MODULE_DISABLE_VERSION
    &ffVersionModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* W[] = {
#if !FF_MODULE_DISABLE_WALLPAPER
    &ffWallpaperModuleInfo,
#endif
#if !FF_MODULE_DISABLE_WEATHER
    &ffWeatherModuleInfo,
#endif
#if !FF_MODULE_DISABLE_WIFI
    &ffWifiModuleInfo,
#endif
    NULL,
};

static FFModuleBaseInfo* X[] = {
    NULL,
};

static FFModuleBaseInfo* Y[] = {
    NULL,
};

static FFModuleBaseInfo* Z[] = {
    NULL,
};

FFModuleBaseInfo** ffModuleInfos[] = {
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
