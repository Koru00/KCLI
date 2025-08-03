#pragma once

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

void enable_raw_mode_linux(struct termios *original);
void disable_raw_mode_linux(struct termios *original);
int kbhit_custom();
int getch_custom();
