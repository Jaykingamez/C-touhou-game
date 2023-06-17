CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
INCLUDE = ./include ./bin/dll
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk4) -Wall $(patsubst %, -I%, $(INCLUDE)) 
DLLFLAGS = -L$(DLLDIR) $(patsubst bin/dll/%.dll, -l%, $(DLL)) 
LIBS = $(shell $(PKGCONFIG) --libs gtk4) -lwinmm
SRC = $(wildcard src/*.c)
EXEDIR = bin/
DISTDIR = dist/
# DLLDIR = bin/dll/
# DLL = $(wildcard bin/dll/*.dll)
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
	ldd $(EXEDIR)$(EXE).exe | grep '\/mingw.*\.dll' -o | xargs -I{} cp "{}" $(EXEDIR)
	cp -r $(EXEDIR) $(EXE)/
	powershell Compress-Archive -F $(EXE)/,$(EXE).exe.lnk $(@)
	rm -rf $(EXE)

clean:
	rm -f $(OBJS)
	rm -f $(EXEDIR)$(EXE).exe
	rm -f $(DISTDIR)$(EXE).zip
