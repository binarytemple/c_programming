CC = gcc -ggdb -std=gnu99
#List all 'c' files by wildcard.
SOURCES=$(wildcard *.c)
#Get the 'exe' equivalent of said file
LIBRARIES=stacking.c
EXECUTABLES=reformat_test.c 
EXECUTABLES+=stacking_test.c

ARGS=-lpthread -lhiredis -I/usr/include/yajl -lyajl 
LIBARGS=-fPIC 

all:   $(EXECUTABLES)
.PHONY: al
$(LIBRARIES): %.o : %.c
	$(CC) $< -o $@ $(ARGS) $(LIBARGS)
$(EXECUTABLES): %.c : %
	$(CC) $< -o $@ $(ARGS)

.PHONY clean:
clean:
	find ./ -type f -executable -delete 
	find ./*.o -delete 

rebuild: clean all
