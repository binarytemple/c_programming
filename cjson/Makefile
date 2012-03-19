CC =  gcc -ggdb -std=gnu99 
ARGS=-lpthread -lhiredis -I/usr/include/yajl -lyajl 
LIBARGS=-fPIC 

rebuild: clean all

all: stacking_test reformat_test linked_list_test

stacking_test: stacking.o stacking_test.o
	$(CC) -o stacking_test stacking.o stacking_test.o $(ARGS)


linked_list_test: 
	$(CC) -o linked_list_test linked_list_test.c $(ARGS)


reformat_test: 
	$(CC) -o reformat_test stacking.o reformat_test.c $(ARGS)

stacking.o: stacking.c
	$(CC) -c -fPIC stacking.c -o stacking.o

stacking_test.o: stacking_test.c
	$(CC) -c $(LIBARGS) stacking_test.c -o stacking_test.o

clean:
	find ./ -type f -executable -delete 
	find ./ -name "*.o" -delete 
