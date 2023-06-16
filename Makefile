CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk4) -I./sound -Wall
LIBS = $(shell $(PKGCONFIG) --libs gtk4) -lwinmm
GLIB_COMPILE_RESOURCES = $(shell $(PKGCONFIG) --variable=glib_compile_resources gio-2.0)
GLIB_COMPILE_SCHEMAS = $(shell $(PKGCONFIG) --variable=glib_compile_schemas gio-2.0)

SRC = action.c  dialogue.c  display_picture.c  hunger.c  main.c  noun.c  parsexec.c  playSound.c  thirst.c  typetext.c
BUILT_SRC = resources.c

OBJS = $(BUILT_SRC:.c=.o) $(SRC:.c=.o)

all: exampleapp

org.gtk.exampleapp.gschema.valid: org.gtk.exampleapp.gschema.xml
	$(GLIB_COMPILE_SCHEMAS) --strict --dry-run --schema-file=$< && mkdir -p $(@D) && touch $@

gschemas.compiled: org.gtk.exampleapp.gschema.valid
	$(GLIB_COMPILE_SCHEMAS) .

resources.c: exampleapp.gresource.xml window.ui
	$(GLIB_COMPILE_RESOURCES) exampleapp.gresource.xml --target=$@ --sourcedir=. --generate-source

%.o: %.c
	$(CC) -c -o $(@F) $(CFLAGS) $<

exampleapp: $(OBJS) gschemas.compiled
	$(CC) -o $(@F) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)
	rm -f exampleapp
