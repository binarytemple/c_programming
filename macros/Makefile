CC = gcc -Wall -save-temps -ggdb -std=gnu99
#List all 'c' files by wildcard.
SOURCES=$(wildcard *.c)
#Get the 'exe' equivalent of said file
EXECUTABLES=$(SOURCES:%.c=%)
#ARGS=`mysql_config --cflags --libs && pkg-config --cflags --libs gtk+-2.0 && pkg-config --cflags --libs sdl`  
ARGS=-lpthread

all: $(EXECUTABLES)
.PHONY: all
$(EXECUTABLES): % : %.c
	$(CC) $< -o $@ $(ARGS)

.PHONY clean:
clean:
	find ./ -type f -executable -delete 
	rm -f *.i
	rm -f *.o
	rm -f *.s

rebuild: clean all
