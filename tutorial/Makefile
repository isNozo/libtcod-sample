CFLAGS = -Wall -Wextra -std=c99 -g -Iinclude -Llib
LDFLAGS = -ltcod-mingw -static-libgcc -static-libstdc++

EXEC = tuto

all: $(EXEC)

$(EXEC): src/main.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	@rm -f $(EXEC)

.PHONY: clean