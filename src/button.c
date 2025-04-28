#include "../include/button.h"

int draw_button(button_t* btn,int cur_y){
    int ret;
    int x,y;
    if(btn->y == cur_y){
        ret = mvprintw(btn->y,btn->x, "{   %s   }",btn->name);

    } else {
        ret = mvprintw(btn->y, btn->x,"[   %s   ]", btn->name);
    }
    return ret;
}
int draw_x_buttons(int btns_len, button_t ** btns,int cur_y){
    for(int i = 0; i<btns_len; i++){
        draw_button(btns[i],cur_y);
    }
    return 0;
}

button_t* create_button(int y, int x, bool sel, char* name){
    if(strlen(name) > 255){
        char short_name[255];
        snprintf(short_name,255,"%s",name);
        strcpy(name,short_name);
    }
    button_t* btn = calloc(1,sizeof(button_t));
    if(btn == NULL){
        perror("calloc failed, btn null");
        return NULL;
    }
    btn->x = x;
    btn->y = y;
    btn->sel = sel;
    strcpy(btn->name, name);
    return btn;
}

int free_buttons(button_t** btns, int btns_len){
    for(int i = 0; i<btns_len; i++){
        free(btns[i]);
    }
    return 0;
}
