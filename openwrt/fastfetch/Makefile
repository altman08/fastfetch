include $(TOPDIR)/rules.mk

PKG_NAME:=fastfetch
PKG_VERSION:=2.66.0
PKG_RELEASE:=1

PKG_LICENSE:=MIT
PKG_LICENSE_FILES:=LICENSE
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
FASTFETCH_SOURCE_DIR:=$(realpath $(CURDIR)/..)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Build/Prepare
	$(RM) -r $(PKG_BUILD_DIR)
	$(INSTALL_DIR) $(PKG_BUILD_DIR)
	$(CP) $(FASTFETCH_SOURCE_DIR)/CMakeLists.txt $(PKG_BUILD_DIR)/
	$(CP) $(FASTFETCH_SOURCE_DIR)/LICENSE $(PKG_BUILD_DIR)/
	$(CP) $(FASTFETCH_SOURCE_DIR)/completions $(PKG_BUILD_DIR)/
	$(CP) $(FASTFETCH_SOURCE_DIR)/doc $(PKG_BUILD_DIR)/
	$(CP) $(FASTFETCH_SOURCE_DIR)/presets $(PKG_BUILD_DIR)/
	$(CP) $(FASTFETCH_SOURCE_DIR)/scripts $(PKG_BUILD_DIR)/
	$(CP) $(FASTFETCH_SOURCE_DIR)/src $(PKG_BUILD_DIR)/
endef

CMAKE_OPTIONS += \
	-DCMAKE_BUILD_TYPE=MinSizeRel \
	-DBUILD_FLASHFETCH=OFF \
	-DSET_TWEAK=OFF \
	-DINSTALL_LICENSE=OFF \
	-DENABLE_WAYLAND=OFF \
	-DENABLE_XCB_RANDR=OFF \
	-DENABLE_XRANDR=OFF \
	-DENABLE_GIO=OFF \
	-DENABLE_DCONF=OFF \
	-DENABLE_DBUS=OFF \
	-DENABLE_SQLITE3=OFF \
	-DENABLE_RPM=OFF \
	-DENABLE_ELF=OFF \
	-DENABLE_LUA=OFF \
	-DENABLE_QUICKJS=OFF \
	-DENABLE_LIBZFS=OFF

define Package/fastfetch
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Fast system information tool
  URL:=https://github.com/fastfetch-cli/fastfetch
endef

define Package/fastfetch/description
Fastfetch is a neofetch-like tool for fetching system information and displaying it in a pretty way.
endef

define Package/fastfetch/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/fastfetch $(1)/usr/bin/fastfetch
endef

$(eval $(call BuildPackage,fastfetch))
