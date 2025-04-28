#include <stdbool.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#define MAX_FILE_DIR_NAME_LENGTH 255

typedef struct button_t {
    int x;
    int y;
    bool sel;
    char name[MAX_FILE_DIR_NAME_LENGTH];
} button_t;

int draw_button(button_t*,int);
button_t* create_button(int,int,bool,char*);
int draw_x_buttons(int, button_t**,int);
int free_buttons(button_t**, int);
