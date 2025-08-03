KCLI - A C Library for CLI Applications
KCLI is a lightweight, cross-platform C library designed to simplify the development of command-line interface (CLI) applications. It provides utilities for handling keyboard input and colored terminal output, with support for both Windows and Linux environments. This project is currently a Work in Progress (WIP), and new features are actively being developed.
Features

Cross-Platform Keyboard Input:
Non-blocking key detection (kbhit_custom) and character input (getch_custom) that work on both Windows and Linux.
Raw mode support for Linux to capture keypresses without requiring Enter.


Colored Terminal Output: ANSI escape codes for regular and bright text colors, as well as background colors, to enhance terminal output.
Modular Design: Organized header and source files for easy integration into your projects.
Build Automation: A Makefile for compiling the library and example programs, with support for dependency tracking and clean builds.

Installation
Prerequisites

GCC: Required for compiling the source code.
Linux: Requires termios.h, unistd.h, and fcntl.h for keyboard input handling.
Windows: Uses conio.h for keyboard input.

Building

Clone the repository:
git clone https://github.com/your-username/KCLI.git
cd KCLI


Build the library and example program:
make

This will create a build directory and compile the KCLI binary.

Run the example:
./KCLI



Cleaning
To remove generated files:
make clean

Usage
The library provides two main modules: keyboard input handling and colored terminal output.
Keyboard Input
Include keyboard.h to use the cross-platform keyboard functions:

kbhit_custom(): Checks if a key has been pressed (non-blocking).
getch_custom(): Reads a single character without echoing to the terminal.
Linux-specific: Use enable_raw_mode_linux() and disable_raw_mode_linux() to manage terminal raw mode.

Example:
#include "keyboard.h"
#include <stdio.h>

int main() {
#ifndef _WIN32
    struct termios original;
    enable_raw_mode_linux(&original);
#endif

    printf("Press any key ('q' to quit):\n");
    while (1) {
        if (kbhit_custom()) {
            int c = getch_custom();
            printf("You pressed: %c (ASCII %d)\n", c, c);
            if (c == 'q') break;
        }
    }

#ifndef _WIN32
    disable_raw_mode_linux(&original);
#endif
    return 0;
}

Colored Output
Include color_print.h to use ANSI escape codes for colored terminal output. Example:
#include "color_print.h"
#include <stdio.h>

int main() {
    printf("%sHello in red!%s\n", RED, RESET_COLOR);
    printf("%sBright green text!%s\n", BRIGHT_GREEN, RESET_COLOR);
    printf("%sWhite text on blue background!%s\n", BG_BLUE WHITE, RESET_COLOR);
    return 0;
}

Project Structure
KCLI/
├── include/
│   ├── color_print.h  # ANSI color definitions
│   ├── keyboard.h     # Keyboard input function declarations
├── lib/
│   ├── color_print.c  # (WIP) Color output implementation
│   ├── keyboard.c     # Keyboard input implementation
├── main.c             # Example program
├── Makefile           # Build configuration
└── README.md          # This file

Contributing
This project is a WIP, and contributions are welcome! To contribute:

Fork the repository.
Create a new branch (git checkout -b feature/your-feature).
Make your changes and commit (git commit -m "Add your feature").
Push to your branch (git push origin feature/your-feature).
Open a pull request.

Please ensure your code follows the existing style and includes appropriate documentation.
TODO

Implement color_print.c with advanced formatting functions.
Add more keyboard input features (e.g., special key detection).
Enhance cross-platform compatibility (e.g., macOS support).
Add unit tests for reliability.
Expand documentation with more examples.

License
This project is licensed under the MIT License.
