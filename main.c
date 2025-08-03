#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "color_print.h"
#include "keyboard.h"


int main() {
#ifdef _WIN32
    printf("Press any key (press 'q' to quit):\n");
#else
    struct termios original;
    enable_raw_mode_linux(&original);
    printf("Press any key (press 'q' to quit):\n");
#endif

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
