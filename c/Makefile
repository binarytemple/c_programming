CC = gcc -ggdb 
#List all 'c' files by wildcard.
SOURCES=$(wildcard *.c)
#Get the 'exe' equivalent of said file
EXECUTABLES=$(SOURCES:%.c=%)
LIBS=-lexpat -luuid  

all: $(EXECUTABLES)
.PHONY: all
$(EXECUTABLES): % : %.c
	$(CC) $< -o $@ $(LIBS)

.PHONY clean:
clean:
	find ./ -type f -executable -delete 
	#find ./ ! -name "*.c" -a ! -name "Makefile" -type f -delete

rebuild: clean all
