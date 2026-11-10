# COS30008 Problem Set 1

**简体中文** | [English](README.md)

## 项目结构

```text
COS30008-Problem-Set-1/
├── include/                 Entity 和迭代器的头文件
├── src/                     C++ 源文件和 main 程序入口
├── CMakeLists.txt            多 IDE 共用的 CMake 构建配置
├── COS30008 Problem Set 1.sln
├── COS30008 Problem Set 1.vcxproj
├── .gitignore
├── README.md
└── README.zh-CN.md
```

`Entity` 在 `include/Entity.h` 中声明。迭代器接口和实现位于 `include/IteratorBase.h`、`include/Iterator1D.h`、`include/Iterator2D.h`、`src/Iterator1D.cpp` 和 `src/Iterator2D.cpp`。`src/main.cpp` 包含示例库存数据和交互式命令循环。

## 克隆项目

将 `<repository-url>` 替换为项目的 Git 仓库地址：

```bash
git clone <repository-url>
cd COS30008-Problem-Set-1
```

## 编译和运行

这是一个 C++17 控制台程序，不依赖第三方库。根目录的 `CMakeLists.txt` 是 VS Code、CLion 和 Visual Studio 共用的构建配置，负责编译 `src/` 下的四个 `.cpp` 文件并添加 `include/` 头文件路径。

### Visual Studio 2022

1. 在 Visual Studio Installer 中安装 **使用 C++ 的桌面开发** 工作负载和 CMake 工具。
2. 在 Visual Studio 中选择 **文件 → 打开 → 文件夹**，打开克隆后的项目目录（包含 `CMakeLists.txt` 的目录）。
3. 在工具栏选择可用的 MSVC x64 CMake 配置，然后生成并运行 `problem-set-1` 目标。

此 CMake 工作流使用 Visual Studio 安装的编译器和工具集，不依赖独立 `.sln` 项目指定的 `v145` 工具集。

### VS Code

安装 VS Code、**C/C++** 和 **CMake Tools** 扩展、CMake 3.20 或更新版本，以及 C++17 编译器。Windows 下可使用 MSYS2 UCRT64 GCC：从 MSYS2 安装后，将其 `bin` 目录加入 `PATH`。打开克隆的项目目录，通过 CMake 状态栏选择工具链、配置、生成并运行 `problem-set-1` 目标。也可以在集成终端直接编译：

```bash
g++ -std=c++17 -Wall -Wextra -I include src/main.cpp src/Entity.cpp src/Iterator1D.cpp src/Iterator2D.cpp -o problem-set-1
```

在终端运行生成的程序：

```bash
./problem-set-1
```

Windows PowerShell 下生成文件名为 `problem-set-1.exe`，使用 `./problem-set-1.exe` 启动。

### 命令行

安装 GCC 或 Clang 并确保编译器已加入 `PATH`，在项目根目录执行：

```bash
g++ -std=c++17 -Wall -Wextra -I include src/main.cpp src/Entity.cpp src/Iterator1D.cpp src/Iterator2D.cpp -o problem-set-1
./problem-set-1
```

若使用 Visual Studio 编译器，请打开 **Developer Command Prompt for VS**，切换到项目根目录后编译并运行：

```bat
cl /std:c++17 /EHsc /W4 /I include src\main.cpp src\Entity.cpp src\Iterator1D.cpp src\Iterator2D.cpp /Fe:problem-set-1.exe
problem-set-1.exe
```

### CLion

在 CLion 中打开克隆后的项目目录。CLion 会自动识别根目录的 `CMakeLists.txt`；选择已配置的 C++ 工具链（MSVC、MinGW、GCC 或 Clang），等待 CMake 重新加载，然后构建并运行 `problem-set-1`。

## 控制台命令

在程序中输入 `help` 查看命令菜单。示例：

```text
e1 print
e1 grab i3
e1 get
e1 next
e2 hp 150
exit
```

`e1` 和 `e2` 用于选择实体。迭代器 `i1`、`i2` 使用一维数组，`i3`、`i4` 使用二维数组。使用 `get`、`next` 或 `previous` 前，需先通过 `grab` 关联迭代器。
