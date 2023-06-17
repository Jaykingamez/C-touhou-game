CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
INCLUDE = ./include
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk4) -Wall $(patsubst %, -I%, $(INCLUDE))
LIBS = $(shell $(PKGCONFIG) --libs gtk4) -lwinmm
SRC = $(wildcard src/*.c)
EXE = bin/TouhouAloneWithAYandere-1.0.1.exe
# BUILT_SRC = src/resources.c
# OBJS = $(BUILT_SRC:src/%.c=obj/%.o) $(SRC:src/%.c=obj/%.o)
OBJS = $(SRC:src/%.c=obj/%.o)

all: $(EXE)

$(OBJS): obj/%.o: src/%.c
	$(CC) -c -o $(@) $(CFLAGS) $<

$(EXE): $(OBJS)
	$(CC) -o $(@) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)
	rm -f $(EXE)
