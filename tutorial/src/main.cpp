#include "libtcod.h"

#define Win_W 60
#define Win_H 30

void print_message(int x, int y, wchar_t *str) {
    for(;*str!='\0';str++)
        TCOD_console_put_char(NULL,x++,y,*str,TCOD_BKGND_DEFAULT);
}

int main() {
    int playerx=0,playery=0;

    TCOD_console_set_custom_font("font.png",TCOD_FONT_LAYOUT_ASCII_INROW,32,2048);
    TCOD_console_init_root(Win_W,Win_H,"libtcod C++ tutorial",false,TCOD_RENDERER_SDL);
    while ( !TCOD_console_is_window_closed() ) {
        TCOD_key_t key;
        TCOD_sys_check_for_event(TCOD_EVENT_KEY_PRESS,&key,NULL);

        switch(key.vk) {
           case TCODK_UP    : playery--; break;
           case TCODK_DOWN  : playery++; break;
           case TCODK_LEFT  : playerx--; break;
           case TCODK_RIGHT : playerx++; break;
           default:break;
       }

        TCOD_console_clear(NULL);
        print_message(playerx, playery, L"あいうえお");
        TCOD_console_flush();
    }
    return 0;
}