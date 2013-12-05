gcc -g --shared -fPIC -c ./testlib.c -o testlib.o 

gcc -dynamiclib -o libtestlib.dylib testlib.o -install_name $(pwd)libtestlib.dylib
