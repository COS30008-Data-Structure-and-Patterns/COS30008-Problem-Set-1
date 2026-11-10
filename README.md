# COS30008 Problem Set 1

[简体中文](README.zh-CN.md) | **English**

## Project structure

```text
COS30008-Problem-Set-1/
├── include/                 Header files for Entity and iterators
├── src/                     C++ source files and main entry point
├── CMakeLists.txt            Shared CMake build configuration
├── COS30008 Problem Set 1.sln
├── COS30008 Problem Set 1.vcxproj
├── .gitignore
├── README.md
└── README.zh-CN.md
```

`Entity` is declared in `include/Entity.h`. The iterator interface and implementations are in `include/IteratorBase.h`, `include/Iterator1D.h`, `include/Iterator2D.h`, `src/Iterator1D.cpp` and `src/Iterator2D.cpp`. `src/main.cpp` contains sample inventory data and the interactive command loop.

## Clone

Replace `<repository-url>` with the Git URL of this project:

```bash
git clone <repository-url>
cd COS30008-Problem-Set-1
```

## Build and run

This is a C++17 console application with no third-party libraries. The root `CMakeLists.txt` is the shared build configuration used by VS Code, CLion and Visual Studio. It compiles the four `.cpp` files under `src/` and adds `include/` to the header search path.

### Visual Studio 2022

1. Install the **Desktop development with C++** workload and CMake tools in Visual Studio Installer.
2. In Visual Studio, select **File → Open → Folder** and open the cloned project folder (the folder containing `CMakeLists.txt`).
3. Select an available MSVC x64 CMake configuration in the toolbar, then build and run the `problem-set-1` target.

This CMake workflow uses the compiler/toolset installed with Visual Studio and does not depend on the separate `.sln` project's `v145` toolset setting.

### VS Code

Install VS Code, the **C/C++** and **CMake Tools** extensions, CMake 3.20 or newer, and a C++17 compiler. For Windows, MSYS2 UCRT64 GCC is one option; install it from MSYS2 and ensure its `bin` directory is on `PATH`. Open the cloned project folder and use the CMake status bar to select a kit, configure, build and run the `problem-set-1` target. Alternatively, build from the integrated terminal:

```bash
g++ -std=c++17 -Wall -Wextra -I include src/main.cpp src/Entity.cpp src/Iterator1D.cpp src/Iterator2D.cpp -o problem-set-1
```

Run the resulting program from the terminal:

```bash
./problem-set-1
```

On Windows PowerShell, the output is `problem-set-1.exe`; run it with `./problem-set-1.exe`.

### Command line

With GCC or Clang available on `PATH`, run the same compile command from the project root:

```bash
g++ -std=c++17 -Wall -Wextra -I include src/main.cpp src/Entity.cpp src/Iterator1D.cpp src/Iterator2D.cpp -o problem-set-1
./problem-set-1
```

For the Visual Studio compiler, open **Developer Command Prompt for VS**, change to the project root, then compile and run:

```bat
cl /std:c++17 /EHsc /W4 /I include src\main.cpp src\Entity.cpp src\Iterator1D.cpp src\Iterator2D.cpp /Fe:problem-set-1.exe
problem-set-1.exe
```

### CLion

Open the cloned project folder in CLion. CLion detects the root `CMakeLists.txt`; select a configured C++ toolchain (MSVC, MinGW, or GCC/Clang), allow CMake to reload, then build and run the `problem-set-1` target.

## Console commands

Enter `help` in the running application to see its command menu. Examples:

```text
e1 print
e1 grab i3
e1 get
e1 next
e2 hp 150
exit
```

`e1` and `e2` select an entity. Iterators `i1` and `i2` use 1D arrays; `i3` and `i4` use 2D arrays. Attach an iterator with `grab` before using `get`, `next` or `previous`.
