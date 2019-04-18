CFLAGS = -Wall -Wextra -std=c99 -g
CPPFLAGS = 
LDFLAGS = -lintl

EXEC = hello

all: $(EXEC) locale/ja/LC_MESSAGES/$(EXEC).mo

$(EXEC): $(EXEC).c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $< $(LDFLAGS)

locale/ja/LC_MESSAGES/$(EXEC).mo: locale/ja/LC_MESSAGES/$(EXEC).po
	msgfmt --output-file=$@ $<

locale/ja/LC_MESSAGES/$(EXEC).po: locale/$(EXEC).pot
	msgmerge --update $@ $<

locale/$(EXEC).pot: $(EXEC).c
	xgettext -k_ -j -s -o locale/hello.pot hello.c

clean:
	@rm -f $(EXEC) locale/ja/LC_MESSAGES/*.mo *~

.PHONY: clean