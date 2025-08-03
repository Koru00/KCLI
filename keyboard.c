#include <stdio.h>
#include <stdlib.h>

#include "keyboard.h"

void enable_raw_mode_linux(struct termios *original) {
#ifndef _WIN32
    struct termios raw;
    tcgetattr(STDIN_FILENO, original);
    raw = *original;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
#endif
}

void disable_raw_mode_linux(struct termios *original) {
#ifndef _WIN32
    tcsetattr(STDIN_FILENO, TCSANOW, original);
#endif
}

int kbhit_custom() {
#ifdef _WIN32
    return _kbhit();
#else
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
#endif
}

int getch_custom() {
#ifdef _WIN32
    return _getch();
#else
    return getchar();  // You must enable raw mode beforehand
#endif
}


