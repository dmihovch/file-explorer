#include "../include/utils.h"





/**
calls functions to init the ncurses environment
 */
int init_ncurses()
{
    initscr();
    noecho();
    cbreak();
    refresh();
    keypad(stdscr, true);
    curs_set(0);
    return 0;
}
