/*
 * Complete roguelike tutorial using C++ and libtcod : 
 * http://www.roguebasin.com/index.php?title=Complete_roguelike_tutorial_using_C%2B%2B_and_libtcod_-_part_1:_setting_up
 */

#include <stdio.h>
#include <libintl.h>
#include <locale.h>
#include "libtcod.h"

#define _(String) gettext (String)
#define gettext_noop(String) String
#define N_(String) gettext_noop (String)

#define Win_W 60
#define Win_H 30

void dump(void *str, int len)
{
    int i;
    int *p = (int *) str;
    printf("c = %s\n", str);
    for(i=0; i<len; i++) {
        printf("[%p] = %08x\n", p, *p);
        p++;
    }
}

void print_message(int x, int y, char *str) {
    for(;*str!='\0';str++)
        TCOD_console_put_char(NULL,x++,y,*str,TCOD_BKGND_DEFAULT);
}

int main()
{
  setlocale (LC_ALL, "");
  bindtextdomain ("hello", "./locale");
  textdomain ("hello");

  int playerx=0,playery=0;
  char *c = _("ABC");

  printf("== %s ==\n", setlocale(LC_ALL, ""));
  dump(c, 3);
  printf("== %s ==\n", setlocale(LC_ALL, "C"));
  dump(c, 3);
  printf("== %s ==\n", setlocale(LC_ALL, "en_US"));
  dump(c, 3);
  printf("== %s ==\n", setlocale(LC_ALL, "ja_JP"));
  dump(c, 3);
  printf("== %s ==\n", setlocale(LC_ALL, ".932"));
  dump(c, 3);
  printf("== %s ==\n", setlocale(LC_ALL, ".20932"));
  dump(c, 3);
  printf("== %s ==\n", setlocale(LC_ALL, ".65001"));
  dump(c, 3);

  TCOD_console_set_custom_font("terminal.png",TCOD_FONT_LAYOUT_ASCII_INCOL,16,16);
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
    print_message(playerx,playery,c);
    TCOD_console_flush();
  }

  return 0;
}
