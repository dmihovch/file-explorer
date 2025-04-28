#include "../include/utils.h"
#include "../include/button.h"


int main(int argc, char* argv[]){

    init_ncurses();

    int y = 0;
    int btns_len = 10;
    button_t* btns[btns_len];
    for(int i = 0; i<btns_len; i++){
        btns[i] = create_button(i, 0, false, "TEST");
        ++y;
    }

    draw_x_buttons(10, btns, y);
    int in;
    y = 0;
    while((in = getch())!= 'q'){
        if(in == KEY_UP){
            if(y > 0){
                y--;
            }
            else{
                y = 0;
            }
        }
        if(in == KEY_DOWN){
            if(y < btns_len-1){
                y++;
            }
            else{
                y = btns_len-1;
            }
        }
        if(in == '\n'){
            mvprintw(15,15,"You selected button %d", y);
        }
        draw_x_buttons(btns_len, btns, y);

        refresh();
    }

    free_buttons(btns, btns_len);
    //need to free buttons

    endwin();
    return 0;
}

/*

WINDOW* win1 = newwin(10, 30, 5, 5);
box(win1, 0, 0);
mvwprintw(win1, 1, 1, "Hello from win1");
wrefresh(win1);
getch();

delwin(win1);  // delete the window before doing something new

clear();       // clear the whole screen
printw("Hello1");
refresh();


*/
