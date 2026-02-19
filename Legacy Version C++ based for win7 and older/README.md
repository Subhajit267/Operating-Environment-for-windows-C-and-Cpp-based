# 🪟 Operating Environment – Legacy Windows Version (C++)

<div align="center">

![C++](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B&logoColor=white)
![Windows](https://img.shields.io/badge/Platform-Windows%207%2B-0078D6?logo=windows&logoColor=white)
![Console API](https://img.shields.io/badge/UI-Windows%20Console%20API-yellow)
![Status](https://img.shields.io/badge/Status-Stable%20(Archival)-brightgreen)

**The original Windows port of Operating Environment, designed for compatibility with older Windows systems (7 and earlier) using the native Console API.**

*This version preserves all features of the Linux releases while adapting to the Windows console environment without relying on ANSI escape sequences.*

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

This is the **first Windows port** of Operating Environment, created to ensure the project could run on older Windows versions (Windows 7, 8, and earlier) where ANSI escape sequence support is limited or absent. Instead of using ANSI codes for colours and cursor positioning, it relies on the **Windows Console API** (`SetConsoleCursorPosition`, `system("color")`, etc.). All applications and features from the Linux v4.23.09 release are present, including:

- TicTacToe (with difficulty levels and cheat codes)
- Quiz (8 rounds, bonus questions, scoreboard)
- Calculator (basic arithmetic)
- Temperature Converter (Celsius, Fahrenheit, Kelvin)
- Linear Equation Solver (pair of equations)
- Quadratic Equation Solver
- Area of Triangle (coordinates)
- User management (login, guest mode, password change)
- Registry system and Registry Editor (power‑user tool)
- Settings panel with three sub‑panels (User Accounts, Reset & Restore, Personalization)
- Colour changer (via `system("color")` – limited to console foreground/background colours)

The code is written in **C++** (with some C‑style I/O) and uses standard C++ libraries alongside Windows‑specific headers.

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
  - **Personalization**: Change console colours (via `system("color")` – limited to 16 combinations).
- **Guest Mode** – Limited commands (`install`, `login`, `exit`) for testing without a user account.
- **Installation Procedure** – First‑run wizard creates user and installs default apps.

### 🖥️ Console Interface
- Uses Windows Console API for cursor positioning (`gotoxy` implemented via `SetConsoleCursorPosition`).
- Colours set via `system("color XY")` where X is background, Y is foreground.
- No ANSI escape sequences – ensures compatibility with Windows 7 and earlier.
- Custom progress bar (simple `||` animation).
- Bootscreens for each application with loading messages.

## 🖥️ Technical Details

### Core Technologies
- **Language**: C++ (compiled with MSVC or MinGW‑GCC).
- **Console Control**: Windows API (`windows.h`, `conio.h`).
- **File I/O**: Standard C++ `fstream` (files stored in `C:\OE\Files\`).
- **Colour Control**: `system("color")` to change entire console palette; individual text colours are not used (all output is default colour).
- **Cursor Positioning**: Custom `gotoxy` using `SetConsoleCursorPosition`.
- **Timing**: `Sleep()` for delays.
- **Randomness**: `rand()` seeded with `time()`.

### File Storage
All persistent data is stored in `C:\OE\`:
- `C:\OE\Files\` – Registry files (`file.txt`, `file2.txt`, `TicTacToe.txt`, etc.)
- `C:\OE\Activation\` – Product key files for TicTacToe and Quiz.
- The installer copies resource files (if any) from a `resources` folder.

### Registry System
Each application has a corresponding `.txt` file containing a single integer:
- `1` = installed
- `0` = not installed
The registry editor can modify these files, and the installer writes them.

### Colour Changer
The personalization menu offers 16 colour choices (corresponding to `system("color")` codes). However, due to the use of `system("color")`, the change affects the entire console and is limited to the 16 standard Windows console colours. The user must restart the program to see the new colour scheme.

## 📦 Building & Running

### Prerequisites
- Windows 7, 8, 10, or 11 (32‑bit or 64‑bit)
- A C++ compiler:
  - Microsoft Visual Studio (any version with C++ support)
  - MinGW‑GCC (e.g., from Code::Blocks or standalone)

### Compilation
#### Using Visual Studio
1. Create a new **Win32 Console Application** project.
2. Add all source files (`main.cpp`, `programs.h`, `sources.h`, `Sources2.h`, `look.h`, `help.h`) to the project.
3. Build the solution (F7).
4. The executable will be created in the `Debug` or `Release` folder.

#### Using MinGW (Command Line)
```bash
g++ -o oe_legacy.exe main.cpp -std=c++11
```
(Note: `-std=c++11` may not be required, but ensures compatibility.)

### Running
1. Ensure you have write permissions to `C:\` (the program creates `C:\OE\` folders).
2. Run `oe_legacy.exe`.
3. If it's the first run, the installer will guide you through user creation and app installation.
4. Follow on‑screen prompts to log in and use the environment.

### Notes
- The program expects a `resources` folder in the same directory as the executable during installation (to copy to `C:\OE\`). If missing, the installation may still work but will not copy any additional files.
- The colour changer writes to `look.h` in `C:\OE\Files\`; if that file is missing, the program will use default colours.

## 📁 File Structure

```
Legacy Version C++ based for win7 and older/
├── README.md                       # This file
├── main.cpp                         # Entry point and main shell
├── look.h                            # Border macro (unused in this version)
├── help.h                            # Help text (may be empty)
├── programs.h                        # Application implementations
├── sources.h                         # Function prototypes, utilities, settings panels
└── Sources2.h                        # Installer, activation, bootscreens, password change, etc.
```

## 🔧 Installation Notes

- The installer creates directories `C:\OE\Files` and `C:\OE\Activation`.
- User credentials are stored in `file.txt` (username) and `file2.txt` (password, or `"0"` if no password).
- Registry files are stored in `C:\OE\Files`.
- The colour changer writes to `look.h` in `C:\OE\Files`, which is read at program start. Changes require a restart.

## 🐞 Known Issues

- **Colour Changer**: Uses `system("color")` which affects the entire console and only offers 16 limited colour combinations. Individual text colouring is not implemented.
- **Uninstall Commands**: Some `unst_*` commands may write to the wrong file (e.g., `unst_Temp_Conv` writes to `TicTacToe.txt` instead of `TC.txt`). This bug is inherited from the Linux versions.
- **Timer Functions**: `timerO` and `timerB` beep repeatedly at 5 seconds; may be annoying.
- **Input Validation**: Entering non‑numeric values where numbers are expected can cause crashes or infinite loops.
- **Progress Bar**: The progress bar is a simple animation that does not reflect actual progress.
- **File Paths**: Hardcoded to `C:\OE\`; may not work if the user lacks write permissions to `C:\`.

## 👨‍💻 Developer

<div align="center">

### **Subhajit Halder** 💻

![Profile](https://img.shields.io/badge/Developer-Subhajit_Halder-blue?style=for-the-badge)

📧 **Email**: [subhajithalder267@outlook.com](mailto:subhajithalder267@outlook.com)

</div>

**Project Background**:  
This legacy Windows port was created to ensure Operating Environment could run on older Windows systems that lack proper ANSI support. It retains all features of the Linux v4.23.09 release while adapting to the Windows Console API. The code is preserved here as an archival snapshot and as a foundation for the modern C port, which uses ANSI sequences for a more faithful visual reproduction of the Linux version.

---

<div align="center">

*A bridge between the Linux origins and the future of Operating Environment on Windows.*

</div>
