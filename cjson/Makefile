CC = gcc -ggdb -std=gnu99
#List all 'c' files by wildcard.
SOURCES=$(wildcard *.c)
#Get the 'exe' equivalent of said file
EXECUTABLES=$(SOURCES:%.c=%)
#ARGS=`mysql_config --cflags --libs && pkg-config --cflags --libs gtk+-2.0 && pkg-config --cflags --libs sdl`  
ARGS=-lpthread -lhiredis -I/usr/include/yajl -lyajl 

all: $(EXECUTABLES)
.PHONY: all
$(EXECUTABLES): % : %.c
	$(CC) $< -o $@ $(ARGS)

.PHONY clean:
clean:
	find ./ -type f -executable -delete 

rebuild: clean all
