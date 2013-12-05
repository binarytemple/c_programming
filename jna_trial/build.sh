


gcc -g --shared -fPIC -c ./testlib.c -o testlib.o 

gcc -dynamiclib -o testlib.dylib testlib.o -install_name $(pwd)testlib.dylib
