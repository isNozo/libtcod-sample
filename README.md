# libtcod-sample

ビルド環境：
- MSYS2, http://repo.msys2.org/distrib/x86_64/msys2-x86_64-20190524.exe

```
$ pacman -S mingw32/mingw-w64-i686-gcc
$ pacman -S mingw32/mingw-w64-i686-make
$ cd tutorial/
$ mingw32-make.exe
cc -Wall -Wextra -std=c99 -g -Iinclude -Llib -o tuto src/main.c -ltcod-mingw -static-libgcc -static-libstdc++
$ ./tuto.exe 
24 bits font.
key color : 255 255 255
```
