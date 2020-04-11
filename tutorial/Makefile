CFLAGS = -Wall -Wextra -std=c99 -g -Iinclude -Llib
LDFLAGS = -ltcod-mingw -lintl -static-libgcc -static-libstdc++

EXEC = hello

all: $(EXEC)

$(EXEC): $(EXEC).c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	@rm -f $(EXEC) locale/ja/LC_MESSAGES/*.mo
.PHONY: clean