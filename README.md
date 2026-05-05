# Fastfetch

Fastfetch 是一款类似 neofetch 的系统信息展示工具，主要用 C 编写，强调性能和可定制性。支持 Linux、macOS、Windows 7+、Android、FreeBSD、OpenBSD、NetBSD、DragonFly、Haiku、SunOS。

示例配置见 presets/examples，更多截图与平台说明见 Wiki。

## 本版本修改说明

### 精简内置 Logo

仅保留常用发行版的内置 Logo（Alpine、Arch、CentOS、Debian、Fastfetch、Fedora、Kali、Linux、Merlin、OpenWrt、Ubuntu），去除其余所有内置 Logo，以减小二进制体积，适配嵌入式设备使用。

当前可用 Logo：
```
fastfetch --list-logos
```
```
 1) "Alpine"
 2) "arch" "archmerge"
 3) "CentOS"
 4) "Debian"
 5) "Fastfetch" "FF"
 6) "Fedora"
 7) "Kali"
 8) "Linux" "linux-generic"
 9) "Merlin" "merlin"
10) "openwrt"
11) "ubuntu" "ubuntu-linux"
```

### 精简模块

移除不需要的功能模块及其底层检测逻辑，当前保留 16 个模块：

| # | 模块 | 说明 |
|---|------|------|
| 1 | Board | 主板名称及信息 |
| 2 | Break | 输出空行 |
| 3 | Command | 执行自定义 Shell 脚本 |
| 4 | Colors | 显示终端 16 色色板 |
| 5 | CPU | CPU 名称、频率等 |
| 6 | Custom | 输出自定义字符串 |
| 7 | DateTime | 当前日期时间 |
| 8 | Disk | 分区、磁盘空间、文件系统等 |
| 9 | Kernel | 系统内核版本 |
| 10 | Loadavg | 系统负载均值 |
| 11 | Memory | 系统内存使用情况 |
| 12 | OS | 操作系统 / Linux 发行版名称及版本 |
| 13 | Packages | 包管理器及已安装包数量 |
| 14 | Separator | 输出分隔线 |
| 15 | Title | 用户名与主机名标题 |
| 16 | Uptime | 系统运行时长 |

### 精简依赖库

在 CMakeLists.txt 中禁用嵌入式设备不需要的可选库：

| 库 | 状态 | 原因 |
|----|------|------|
| wayland-client | 禁用 | Display 模块已移除 |
| xcb-randr | 禁用 | Display 模块已移除 |
| xrandr | 禁用 | Display 模块已移除 |
| dbus-1 | 禁用 | 相关模块（Wallpaper/Icons/Editor）已移除 |
| libelf | 禁用 | ELF 二进制解析模块已移除 |

### 精简底层公共模块

移除以下不再使用的公共实现文件：

- `edidHelper`（EDID 显示器信息解析）
- `font`（字体检测）
- `base64`（Base64 编解码）
- `binary`（ELF 二进制解析，全平台）
- `kmod`（内核模块加载，全平台）

### Logo 图像功能精简

移除所有图像类型 Logo 显示功能（sixel / kitty / iterm / chafa / raw），仅保留 ASCII 文字 Logo。

## 安装

Linux（部分）：
- Debian 13+ / Ubuntu: apt install fastfetch
- Arch: pacman -S fastfetch
- Fedora: dnf install fastfetch
- openSUSE: zypper install fastfetch
- Linuxbrew：brew install fastfetch
- 各发行版打包状态：https://repology.org/project/fastfetch/versions

macOS：
- Homebrew：brew install fastfetch
- MacPorts：sudo port install fastfetch

Windows：
- scoop install fastfetch
- choco install fastfetch
- winget install fastfetch
- MSYS2：pacman -S mingw-w64-<subsystem>-<arch>-fastfetch

BSD：
- FreeBSD：pkg install fastfetch
- NetBSD：pkgin in fastfetch
- OpenBSD：pkg_add fastfetch

Android（Termux）：
- pkg install fastfetch

Nightly 构建：
- https://nightly.link/fastfetch-cli/fastfetch/workflows/ci/dev?preview

## 源码构建

基本上是 `cmake . && make`。详见 Wiki：https://github.com/fastfetch-cli/fastfetch/wiki/Building

## 使用

- 默认运行：`fastfetch`
- 查看所有可用模块示例：`fastfetch -c all.jsonc`
- 以 JSON 输出指定模块：`fastfetch -s <module1>[:<module2>] --format json`
- 完整命令行帮助：`fastfetch --help`
- 生成最小配置：`fastfetch --gen-config [</path/to/config.jsonc>]`
  - 生成完整配置：`fastfetch --gen-config-full`
  - 请使用支持 JSON schema 的编辑器（如 VSCode）编辑配置文件！
  - 如果你连接 Github 有网络困难（智能提示不生效），可将配置文件中的 `$schema` 的值替换为 `https://gitee.com/carterl/fastfetch/raw/dev/doc/json_schema.json`

## 定制

- 配置使用 JSONC，语法与选项见 Wiki：https://github.com/fastfetch-cli/fastfetch/wiki/Configuration
- 预设示例位于 presets，可用 `-c <filename>` 加载
- Logo 选项与图像显示见文档：https://github.com/fastfetch-cli/fastfetch/wiki/Logo-options
- 模块格式化（示例，仅显示 CPU 名称）：
```jsonc
{
  "modules": [
    { "type": "cpu", "format": "{name}" }
  ]
}
```
详见：https://github.com/fastfetch-cli/fastfetch/wiki/Format-String-Guide

## 反馈与支持

- 使用问题：Discussions https://github.com/fastfetch-cli/fastfetch/discussions
- 疑似缺陷：Issues https://github.com/fastfetch-cli/fastfetch/issues（请填写模版）

## 赞助

<img src="https://github.com/user-attachments/assets/a36a6501-e8b0-4a10-9061-b9206d12ffba" width="220">
