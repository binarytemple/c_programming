CC = gcc -ggdb -std=gnu99 -Wall  

all: example

example: 
	$(CC) $< static.c static1.c -o $@

static.o:


clean:
	find ./ -type f -executable -delete 

rebuild: clean all
