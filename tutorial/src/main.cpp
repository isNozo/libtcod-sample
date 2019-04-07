#include "libtcod.h"
int main() {
    int playerx=40,playery=25;
    TCOD_console_init_root(80,50,"libtcod C++ tutorial",false,TCOD_RENDERER_SDL);
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
        TCOD_console_put_char(NULL,playerx,playery,'@',TCOD_BKGND_DEFAULT);
        TCOD_console_flush();
    }
    return 0;
}