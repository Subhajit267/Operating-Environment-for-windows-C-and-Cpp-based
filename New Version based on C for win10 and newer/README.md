# 🪟 Operating Environment – Modern Windows Version (C)

<div align="center">

![C](https://img.shields.io/badge/Language-C-blue?logo=c&logoColor=white)
![Windows](https://img.shields.io/badge/Platform-Windows%2010%2B-0078D6?logo=windows&logoColor=white)
![ANSI](https://img.shields.io/badge/UI-ANSI%20Escape%20Sequences-brightgreen)
![Status](https://img.shields.io/badge/Status-Stable%20%7C%20Active-brightgreen)

**A complete rewrite of Operating Environment in C, bringing the full Linux feature set to modern Windows using ANSI escape sequences for a vibrant console experience.**

*This version is the direct predecessor of the `oe-reboot` project, designed with portability in mind and ready for future bare‑metal adaptation.*

</div>

## 📋 Table of Contents
- [🌟 Overview](#-overview)
- [✨ Features](#-features)
- [🖥️ Technical Details](#️-technical-details)
- [📦 Building & Running](#-building--running)
- [📁 File Structure](#-file-structure)
- [🔧 Installation Notes](#-installation-notes)
- [🐞 Known Issues](#-known-issues)
- [👨‍💻 Developer](#-developer)

## 🌟 Overview

This is the **modern Windows port** of Operating Environment, rewritten entirely in **C** (no C++). It targets Windows 10 and later, taking advantage of built‑in ANSI escape sequence support in the console. As a result, the visual appearance is identical to the Linux v4.23.09 release – complete with coloured borders, styled text, and a polished UI.

All applications from the Linux version are included, along with the full suite of system features: user management, registry editor, settings panels, and more. The code is structured to be platform‑independent (ANSI sequences are standard) and serves as the foundation for the upcoming `oe-reboot` project, which aims to run on bare metal.

## ✨ Features

### 🎮 Applications
- **TicTacToe** – Player vs. Player or Computer (Easy/Hard modes). Cheat code: type `w` during move selection to win instantly.
- **Quiz** – Two‑player quiz with 8 questions, bonus rounds, and a detailed scoreboard. Includes about, evaluator, and cheat sheet screens.
- **Calculator** – Performs arithmetic with three operators (e.g., `5+3*2-4`).
- **Temperature Converter** – Converts between Celsius, Fahrenheit, and Kelvin.
- **Linear Equation Solver** – Solves two equations in two variables using cross‑multiplication. Handles different equation forms.
- **Quadratic Equation Solver** – Solves `ax²+bx+c=0` and reports root types (real/equal, real/unequal, imaginary).
- **Area of Triangle** – Calculates area from three coordinate pairs.

### 🔧 System Features
- **User Management** – Login with password, guest mode, password change, user ID change.
- **Registry System** – Text files track application installation status (e.g., `TicTacToe.txt`).
- **Registry Editor** – Hidden tool for power users (accessible via `registryeditor` command). Allows installing/uninstalling apps, running temporary trials, and managing users.
- **Settings Panel** – Three sub‑panels:
  - **User Accounts**: Change password, change user ID.
  - **Reset & Restore**: Reset all apps or reinstall the system.
  - **Personalization**: Change border colour (16 options, modifies `looks.h` and requires restart).
- **Guest Mode** – Limited commands (`install`, `login`, `exit`) for testing without a user account.
- **Installation Procedure** – First‑run wizard creates user and installs default apps.

### 🖥️ Console Interface
- Uses **ANSI escape sequences** for colours, cursor positioning, and text styling (identical to the Linux version).
- Custom progress bar with `-` and `_` characters.
- Bootscreens for each application with loading messages.
- The border colour can be changed via the Personalization menu (writes to `looks.h`).

## 🖥️ Technical Details

### Core Technologies
- **Language**: Pure C (C99/C11).
- **Console Control**: ANSI escape sequences (`\x1B[` codes). Windows 10 and later support these when the console is in virtual terminal mode (enabled by default in recent versions).
- **File I/O**: Standard C `fopen`, `fprintf`, etc. (files stored in current directory by default).
- **Colour Control**: Macros defined in `looks.h` (e.g., `#define border "\x1B[41m"`). The colour changer rewrites this file.
- **Cursor Positioning**: Custom `gotoxy` using ANSI: `printf("%c[%d;%df", 0x1B, y, x);`.
- **Timing**: `Sleep()` from `windows.h` for delays (can be replaced with a portable function later).
- **Randomness**: `rand()` seeded with `time()`.

### Registry System
Each application has a corresponding `.txt` file containing a single integer:
- `1` = installed
- `0` = not installed
The registry editor can modify these files, and the installer writes them.

### Colour Changer
- The Personalization menu offers 16 colour choices, each mapped to an ANSI background code.
- When a colour is selected, the program overwrites `looks.h` with the new `#define border` line and then exits with a message, requiring a restart to apply the change.
- This simple mechanism allows runtime customization without recompilation.

### Portability Notes
- All console I/O uses ANSI sequences, which are also supported on Linux/macOS. The code could be compiled for those platforms with minimal changes (replace `Sleep` with `usleep`, and remove Windows‑specific headers).
- This version is a stepping stone to the `oe-reboot` project, which will further abstract platform dependencies.

## 📦 Building & Running

### Prerequisites
- Windows 10 (build 14393 or later) or Windows 11.
- A C compiler:
  - MinGW‑GCC (e.g., from Code::Blocks or standalone)
  - Microsoft Visual Studio (with C support)
  - Clang for Windows

### Compilation
#### Using MinGW (Command Line)
```bash
gcc -o oe_modern.exe main.c -std=c99
```

#### Using Visual Studio
1. Create a new **Console Application** project in C.
2. Add all source files (`main.c`, `programs.h`, `sources.h`, `Sources2.h`, `looks.h`) to the project.
3. Build the solution.

### Running
- Simply run the executable. If it's the first run, the installer will guide you through user creation and app installation.
- Ensure your console supports ANSI escape sequences (default in Windows 10/11). If colours don't appear, you may need to enable virtual terminal processing manually (or run in a terminal like Windows Terminal).

## 📁 File Structure

```
New Version based on C for win10 and newer/
├── README.md                       # This file
├── main.c                           # Entry point and main shell
├── looks.h                           # Border colour macro (can be modified by color_change)
├── programs.h                        # Application implementations (TicTacToe, Quiz, solvers, etc.)
├── sources.h                         # Function prototypes, utilities, settings panels
└── Sources2.h                        # Installer, activation, bootscreens, password change, etc.
```

## 🔧 Installation Notes

- The installer creates the necessary registry files in the current directory (not in `C:\OE` as in the legacy version).
- User credentials are stored in `file.txt` (username) and `file2.txt` (password, or `"0"` if no password).
- Registry files (`TicTacToe.txt`, `Quiz.txt`, etc.) are also created in the current directory.
- The colour changer writes to `looks.h`; if that file is missing, the program will use the default border colour defined in `main.c` (but `looks.h` is included, so it must exist). The installer does not create `looks.h` – it is provided with the source.

## 🐞 Known Issues

- **Uninstall Commands**: Some `unst_*` commands may write to the wrong file (inherited from the Linux versions). For example, `unst_Temp_Conv` writes to `TicTacToe.txt` instead of `TC.txt`. This is a known bug.
- **Timer Functions**: `timerO` and `timerB` beep repeatedly at 5 seconds; may be annoying.
- **Input Validation**: Entering non‑numeric values where numbers are expected can cause crashes or infinite loops.
- **Progress Bar**: The progress bar is a simple simulation and does not reflect actual progress; it stops at 25% in many places (a debugging leftover).
- **Colour Changer**: Requires a program restart to take effect; no dynamic reloading.
- **File Paths**: All files are stored in the current directory; no central installation location like `C:\OE`. This may clutter the working directory.

## 👨‍💻 Developer

<div align="center">

### **Subhajit Halder** 💻

![Profile](https://img.shields.io/badge/Developer-Subhajit_Halder-blue?style=for-the-badge)

📧 **Email**: [subhajithalder267@outlook.com](mailto:subhajithalder267@outlook.com)

</div>

**Project Background**:  
This modern C port was created to bring the full Linux experience to Windows 10/11 while preparing the codebase for future bare‑metal use. By using ANSI escape sequences, it achieves visual parity with the Linux version and eliminates platform‑specific console API calls. The code is leaner, more portable, and serves as the foundation for the `oe-reboot` project.

---

<div align="center">

*A clean, C‑based foundation for the next generation of Operating Environment.*

</div>
