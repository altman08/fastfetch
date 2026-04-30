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

移除不需要的功能模块及其底层检测逻辑，当前保留 43 个模块：

| # | 模块 | 说明 |
|---|------|------|
| 1 | Board | 主板名称及信息 |
| 2 | Break | 输出空行 |
| 3 | Btrfs | Linux BTRFS 卷信息 |
| 4 | Command | 执行自定义 Shell 脚本 |
| 5 | Colors | 显示终端 16 色色板 |
| 6 | CPU | CPU 名称、频率等 |
| 7 | CPUCache | CPU 缓存大小 |
| 8 | CPUUsage | CPU 使用率 |
| 9 | Custom | 输出自定义字符串 |
| 10 | DateTime | 当前日期时间 |
| 11 | Display | 分辨率、刷新率等 |
| 12 | Disk | 分区、磁盘空间、文件系统等 |
| 13 | DiskIO | 物理磁盘 I/O 吞吐量 |
| 14 | DNS | 已配置的 DNS 服务器 |
| 15 | Editor | 默认编辑器信息 |
| 16 | Host | 计算机产品名称 |
| 17 | Icons | 图标主题名称 |
| 18 | InitSystem | Init 系统（PID 1）名称及版本 |
| 19 | Kernel | 系统内核版本 |
| 20 | Loadavg | 系统负载均值 |
| 21 | Locale | 系统语言区域设置 |
| 22 | LocalIp | 本地 IP / MAC 地址等 |
| 23 | Logo | JSON 输出内置 Logo |
| 24 | Memory | 系统内存使用情况 |
| 25 | NetIO | 网络 I/O 吞吐量 |
| 26 | OS | 操作系统 / Linux 发行版名称及版本 |
| 27 | Packages | 包管理器及已安装包数量 |
| 28 | PhysicalDisk | 物理磁盘信息 |
| 29 | PhysicalMemory | 物理内存设备信息 |
| 30 | Processes | 运行中进程数量 |
| 31 | PublicIp | 公网 IP 地址及相关信息 |
| 32 | Separator | 输出分隔线 |
| 33 | Shell | 当前 Shell 名称及版本 |
| 34 | Swap | 交换空间使用情况 |
| 35 | Terminal | 当前终端名称及版本 |
| 36 | TerminalSize | 当前终端尺寸 |
| 37 | Title | 用户名与主机名标题 |
| 38 | Uptime | 系统运行时长 |
| 39 | Users | 当前登录用户 |
| 40 | Version | Fastfetch 版本及构建信息 |
| 41 | Wallpaper | 当前壁纸文件路径 |
| 42 | Weather | 天气信息 |
| 43 | Wifi | 已连接 Wi-Fi 信息 |

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
