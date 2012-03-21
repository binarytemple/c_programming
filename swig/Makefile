CC =  gcc -ggdb -std=gnu99 
ARGS=-lpthread -lhiredis -I/usr/include/yajl -lyajl 
LIBARGS=-fPIC 
PERL_OPTS=`perl -MExtUtils::Embed -e ccopts -e ldopts -e iopts | tr "\n" " "`
PYTHON_OPTS=`pkg-config --libs --cflags python`
rebuild: clean all

all: area.so

area.o: area.c
	$(CC) -c -fPIC area.c -o area.o

area.pm area_perl_wrap.c: area.c area.i
	swig -perl5 -o area_perl_wrap.c -d perldir area.i

area.py area_python_wrap.c: area.c area.i
	swig -python -o area_python_wrap.c -d pythondir area.i

area_perl_wrap.o : area.pm area_perl_wrap.c
	$(CC) -c -fPIC -Dbool=char -D_GNU_SOURCE $(PERL_OPTS) area.c area_perl_wrap.c

area_python_wrap.o : area.py area_python_wrap.c 
	$(CC) -c -fPIC -Dbool=char -D_GNU_SOURCE $(PYTHON_OPTS) area.c area_python_wrap.c

area.so : area.o area_perl_wrap.o area_python_wrap.o
	$(CC) -shared -FPIC -Dbool=char $(PYTHON_OPTS) $(PERL_OPTS) area.o area_python_wrap.o area_perl_wrap.o -o area.so

clean:
	find ./ -name "*.o" -delete 
	find ./ -name "*.so" -delete 
	rm -f area_python_wrap.c area_perl_wrap.c area.pm area.py
