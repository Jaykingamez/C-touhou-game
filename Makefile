CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk4) -I./sound -Wall
LIBS = $(shell $(PKGCONFIG) --libs gtk4) -lwinmm

SRC = action.c  dialogue.c  display_picture.c  hunger.c  main.c  noun.c  parsexec.c  playSound.c  thirst.c  typetext.c
BUILT_SRC = resources.c

OBJS = $(BUILT_SRC:.c=.o) $(SRC:.c=.o)

all: Output

%.o: %.c
	$(CC) -c -o $(@F) $(CFLAGS) $<

Output: $(OBJS)
	$(CC) -o $(@F) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)
	rm -f Output
