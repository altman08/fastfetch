#include "modules/modules.h"

static FFModuleBaseInfo* A[] = {
    NULL,
};

static FFModuleBaseInfo* B[] = {
    &ffBoardModuleInfo,
    &ffBreakModuleInfo,
    &ffBtrfsModuleInfo,
    NULL,
};

static FFModuleBaseInfo* C[] = {
    &ffCommandModuleInfo,
    &ffColorsModuleInfo,
    &ffCPUModuleInfo,
    &ffCPUCacheModuleInfo,
    &ffCPUUsageModuleInfo,
    &ffCustomModuleInfo,
    NULL,
};

static FFModuleBaseInfo* D[] = {
    &ffDateTimeModuleInfo,
    &ffDisplayModuleInfo,
    &ffDiskModuleInfo,
    &ffDiskIOModuleInfo,
    &ffDNSModuleInfo,
    NULL,
};

static FFModuleBaseInfo* E[] = {
    &ffEditorModuleInfo,
    NULL,
};

static FFModuleBaseInfo* F[] = {
    NULL,
};

static FFModuleBaseInfo* G[] = {
    NULL,
};

static FFModuleBaseInfo* H[] = {
    &ffHostModuleInfo,
    NULL,
};

static FFModuleBaseInfo* I[] = {
    &ffIconsModuleInfo,
    &ffInitSystemModuleInfo,
    NULL,
};

static FFModuleBaseInfo* J[] = {
    NULL,
};

static FFModuleBaseInfo* K[] = {
    &ffKernelModuleInfo,
    NULL,
};

static FFModuleBaseInfo* L[] = {
    &ffLoadavgModuleInfo,
    &ffLocaleModuleInfo,
    &ffLocalIPModuleInfo,
    &ffLogoModuleInfo,
    NULL,
};

static FFModuleBaseInfo* M[] = {
    &ffMemoryModuleInfo,
    NULL,
};

static FFModuleBaseInfo* N[] = {
    &ffNetIOModuleInfo,
    NULL,
};

static FFModuleBaseInfo* O[] = {
    &ffOSModuleInfo,
    NULL,
};

static FFModuleBaseInfo* P[] = {
    &ffPackagesModuleInfo,
    &ffPhysicalDiskModuleInfo,
    &ffPhysicalMemoryModuleInfo,
    &ffProcessesModuleInfo,
    &ffPublicIPModuleInfo,
    NULL,
};

static FFModuleBaseInfo* Q[] = {
    NULL,
};

static FFModuleBaseInfo* R[] = {
    NULL,
};

static FFModuleBaseInfo* S[] = {
    &ffSeparatorModuleInfo,
    &ffShellModuleInfo,
    &ffSwapModuleInfo,
    NULL,
};

static FFModuleBaseInfo* T[] = {
    &ffTerminalModuleInfo,
    &ffTerminalSizeModuleInfo,
    &ffTitleModuleInfo,
    NULL,
};

static FFModuleBaseInfo* U[] = {
    &ffUptimeModuleInfo,
    &ffUsersModuleInfo,
    NULL,
};

static FFModuleBaseInfo* V[] = {
    &ffVersionModuleInfo,
    NULL,
};

static FFModuleBaseInfo* W[] = {
    &ffWallpaperModuleInfo,
    &ffWeatherModuleInfo,
    &ffWifiModuleInfo,
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
