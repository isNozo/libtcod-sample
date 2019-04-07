#include "libtcod.h"
int main() {
   TCOD_console_init_root(80,50,"libtcod C++ tutorial",false,TCOD_RENDERER_OPENGL);
   while ( !TCOD_console_is_window_closed() ) {
       TCOD_key_t key;
       TCOD_sys_check_for_event(TCOD_EVENT_KEY_PRESS,&key,NULL);
       TCOD_console_clear(NULL);
       TCOD_console_put_char(NULL, 40,25,'@',TCOD_BKGND_DEFAULT);
       TCOD_console_flush();
   }
   return 0;
}