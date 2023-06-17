CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
INCLUDE = ./include
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk4) -Wall $(patsubst %, -I%, $(INCLUDE))
LIBS = $(shell $(PKGCONFIG) --libs gtk4) -lwinmm
SRC = $(wildcard src/*.c)
EXEDIR = bin/
DISTDIR = dist/
EXE = TouhouAloneWithAYandere-1.0.1
# BUILT_SRC = src/resources.c
# OBJS = $(BUILT_SRC:src/%.c=obj/%.o) $(SRC:src/%.c=obj/%.o)
OBJS = $(SRC:src/%.c=obj/%.o)

all: $(EXEDIR)$(EXE).exe $(DISTDIR)$(EXE).zip

$(OBJS): obj/%.o: src/%.c
	$(CC) -c -o $(@) $(CFLAGS) $<

$(EXEDIR)$(EXE).exe: $(OBJS)
	$(CC) -o $(@) $(OBJS) $(LIBS)
	
$(DISTDIR)$(EXE).zip: $(EXEDIR)$(EXE).exe
	cp -r $(EXEDIR) $(EXE)/
	powershell Compress-Archive -F $(EXE)/ $(@)
	rm -rf $(EXE)


clean:
	rm -f $(OBJS)
	rm -f $(EXEDIR)$(EXE).exe
	rm -f $(DISTDIR)$(EXE).zip
