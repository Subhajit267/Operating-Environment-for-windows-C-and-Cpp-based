# 🪟 Operating Environment – Windows Ports

<div align="center">

![C++](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B&logoColor=white)
![C](https://img.shields.io/badge/Language-C-blue?logo=c&logoColor=white)
![Windows](https://img.shields.io/badge/Platform-Windows%207%2B-0078D6?logo=windows&logoColor=white)
![Console](https://img.shields.io/badge/UI-Console%20API%20%7C%20ANSI-brightgreen)

**This repository contains two distinct Windows ports of the Operating Environment project**

*One preserves compatibility with older Windows systems (7 and earlier) using the native Console API; the other brings the full feature set of the Linux versions to modern Windows 10/11 using ANSI escape sequences for a consistent look and feel.*

</div>

## 📋 Table of Contents
- [🌟 Overview](#-overview)
- [📁 Repository Structure](#-repository-structure)
- [🪟 Legacy C++ Version (Windows 7 and older)](#-legacy-c-version-windows-7-and-older)
  - [Features](#features)
  - [Technical Details](#technical-details)
  - [Building & Running](#building--running)
- [✨ Modern C Version (Windows 10/11)](#-modern-c-version-windows-1011)
  - [Features](#features-1)
  - [Technical Details](#technical-details-1)
  - [Building & Running](#building--running-1)
- [🔄 From Linux to Windows: The Porting Journey](#-from-linux-to-windows-the-porting-journey)
- [🔧 Technical Comparison](#-technical-comparison)
- [👨‍💻 Developer](#-developer)

## 🌟 Overview

After the original Linux‑based versions of Operating Environment (v1.0 through v4.23.09), the project was ported to Windows to broaden its reach and to explore platform‑specific console programming. This repository archives two distinct Windows ports:

1. **Legacy C++ Version** – Written in C++, it targets Windows 7 and earlier by using the Windows Console API directly. It does **not** rely on ANSI escape sequences, ensuring compatibility with older systems where ANSI support is limited or absent.

2. **Modern C Version** – A complete rewrite in **C** (with no C++ features) that replicates the look and feel of the Linux v4.23.09 release. It uses ANSI escape sequences (enabled in Windows 10 and later) to achieve the same colourful, styled interface as the Linux version. This port is a stepping stone toward a future bare‑metal OS shell.

Both versions include the full suite of applications: TicTacToe, Quiz, Calculator, Temperature Converter, Linear Equation Solver, Quadratic Equation Solver, and – in the modern version – the Area of Triangle calculator. They also feature user management, a registry editor, and a settings panel.

## 📁 Repository Structure

```
OE_Windows Based/
├── README.md                         # You are here
├── Legacy Version C++ based for win7 and older/
│   ├── README.md                      # Details specific to this version
│   ├── main.cpp                        # Entry point and main shell
│   ├── look.h                           # Colour macros (using Console API)
│   ├── help.h                           # Help text
│   ├── programs.h                       # Application implementations
│   ├── sources.h                        # Function declarations and globals
│   └── sources2.h                       # Additional functions (installer, registry)
└── New Version based on C for win10 and newer/
    ├── README.md                      # Details specific to this version
    ├── main.c                           # Entry point and main shell (C version)
    ├── look.h                           # ANSI colour macros (same as Linux)
    ├── help.h                           # Help text
    ├── programs.h                       # Application implementations (C)
    ├── sources.h                        # Function declarations and globals
    └── sources2.h                       # Additional functions (C)
```

## 🪟 Legacy C++ Version (Windows 7 and older)

This version was created to keep Operating Environment usable on older Windows systems that lack proper ANSI escape sequence support. It uses the Windows Console API for all screen manipulation.

### Features
- **Full application suite**: TicTacToe, Quiz, Calculator, Temperature Converter, Linear Equation Solver, Quadratic Equation Solver.
- **User management**: Login with password, guest mode, password change.
- **Registry system**: Text‑based registry files track app installation status.
- **Registry Editor**: Hidden tool for power users (accessible via `reg_edit`).
- **Settings panel**: Basic options (password change, reset, etc.).
- **Bootscreens** and a simple layout.

### Technical Details
- **Language**: C++ (with some C‑style I/O).
- **Console control**: Uses `SetConsoleTextAttribute`, `SetConsoleCursorPosition`, and `system("cls")`.
- **Colours**: Defined via macros in `look.h` that map to Windows console colour codes (e.g., `FOREGROUND_RED | FOREGROUND_INTENSITY`).
- **Input**: `cin` and `getchar()`.
- **File I/O**: Standard C++ `fstream`.
- **No ANSI escape sequences** – everything is done through the Windows API.

### Building & Running
- **Compiler**: Visual Studio (any version) or MinGW‑GCC (with Windows SDK).
- **Build**: Open the source files in a console project and compile.
- **Run**: Execute the resulting `.exe` on Windows 7, 8, 10, or 11 (though on newer systems the modern version is recommended).

## ✨ Modern C Version (Windows 10/11)

This version is a faithful port of the Linux v4.23.09 release to C, targeting modern Windows. It uses ANSI escape sequences (enabled in Windows 10 Threshold 2 and later) to achieve the same visual appearance as the Linux version, including coloured borders, logos, and styled text.

### Features
- **All applications from Linux v4.23.09**, including the new Area of Triangle calculator (`ar(t_c)`).
- **Full ANSI colour support** – exactly the same escape sequences as the Linux version.
- **C language** – no C++ features, making the code simpler and more portable.
- **Modular settings** – User Accounts, Reset & Restore, Personalization (with 16‑colour border changer).
- **Whoami command** – displays current username.
- **Registry editor** with admin/normal modes.
- **Guest mode** with limited commands.

### Technical Details
- **Language**: Pure C (C99/C11).
- **Console control**: ANSI escape sequences (`\x1B[` codes) for colours, cursor movement, and clearing. These are supported in Windows 10 and later when the console is in virtual terminal mode.
- **Colours**: Defined via macros in `look.h` (same as Linux). The border colour can be changed dynamically by rewriting `looks.h` and restarting.
- **Input**: `scanf` and `getchar()` (with some use of `cin` in the legacy version, but here it's all C I/O).
- **File I/O**: Standard C `fopen`, `fprintf`, etc.
- **Bootscreens** and progress bars work exactly as in the Linux version.

### Building & Running
- **Compiler**: MinGW‑GCC or any C compiler that targets Windows (e.g., Clang, MSVC with `/std:c11`).
- **Build**: Compile all `.c` files together.
  ```bash
  gcc -o oe_modern.exe main.c programs.c sources.c sources2.c
  ```
- **Run**: Execute on Windows 10 (build 14393 or later) or Windows 11. Ensure the console supports virtual terminal sequences (default in modern Windows).

## 🔄 From Linux to Windows: The Porting Journey

The Windows ports represent a significant cross‑platform effort:

1. **Linux C++ → Legacy Windows C++**: The first port adapted the Linux code to use the Windows Console API instead of ANSI escapes. This involved replacing all `printf` with `cout` (or keeping `printf` but using Windows colour functions) and implementing cursor positioning via `SetConsoleCursorPosition`. The result was a fully functional Windows version that looked different (using the classic Windows colour scheme) but retained all features.

2. **Legacy C++ → Modern C (with ANSI)**: The modern version took a different approach: it preserved the ANSI escape sequences from the Linux code and relied on Windows 10’s virtual terminal support. This allowed the exact same source code (converted to C) to run on both Linux and Windows, with identical visual output. This version also stripped out C++ features, making the code leaner and more suitable for eventual bare‑metal use.

The modern C version is now the foundation for future development, including the planned `oe-reboot` project that aims to create a portable, platform‑independent shell ready for a custom OS.

## 🔧 Technical Comparison

| Feature                | Legacy C++ Version (Win7+)          | Modern C Version (Win10+)            |
|------------------------|-------------------------------------|--------------------------------------|
| Language               | C++                                 | C                                    |
| Console Control        | Windows Console API                 | ANSI escape sequences                |
| Colour Support         | 16 colours via `SetConsoleTextAttribute` | Full 256‑colour ANSI (backgrounds, etc.) |
| Cursor Positioning     | `SetConsoleCursorPosition`          | `\x1B[y;xH` escape                    |
| Screen Clearing        | `system("cls")`                     | `\x1B[2J` or `system("cls")`         |
| Code Structure         | Multiple headers with definitions   | Same, but all in C                    |
| New Apps (e.g., area)  | No                                   | Yes                                   |
| Color Changer          | No                                   | Yes (16 options)                      |
| Settings Panels        | Basic                                | Modular (User, Reset, Personalization)|
| Guest Mode              | Yes                                  | Yes                                   |

## 👨‍💻 Developer

<div align="center">

### **Subhajit Halder** 💻

![Profile](https://img.shields.io/badge/Developer-Subhajit_Halder-blue?style=for-the-badge)

📧 **Email**: [subhajithalder267@outlook.com](mailto:subhajithalder267@outlook.com)

</div>

**Project Background**:  
The Windows ports were created to ensure Operating Environment could run on the most common desktop OS. The legacy version preserves compatibility with older machines, while the modern version brings the full Linux experience to Windows 10/11. Together, they demonstrate the evolution of the project and the developer’s growing expertise in cross‑platform development.

The modern C version, in particular, is a crucial step toward the ultimate goal: a clean, portable codebase that can be compiled for bare metal, forming the core of a future custom OS shell.

---

<div align="center">

*From Linux to Windows, the environment keeps growing – now ready for the next generation.*

</div>
