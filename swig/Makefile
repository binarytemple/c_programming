CC=gcc -ggdb -std=gnu99 
ARGS=-lpthread -lhiredis -I/usr/include/yajl -lyajl 
LIBARGS=-fPIC 
PERL_OPTS=`perl -MExtUtils::Embed -e ccopts -e ldopts -e iopts | tr "\n" " "`
PYTHON_OPTS=`pkg-config --libs --cflags python`
JAVA_OPTS=-I'$(JAVA_HOME)'/include -I'$(JAVA_HOME)'/include/linux

rebuild: clean all

bindings: area.so py/_area.so pl/area.so java/libs/libarea.so 
java_examples: area.class areaJNI.class JavaTest.class PrintLibraryPath.class

all: area.so bindings java_examples

area.o: area.c
	$(CC) -c -fPIC area.c -o area.o

pl/area.pm pl/area_wrap.c: area.c area.i
	swig -perl5 -o pl/area_wrap.c -outdir pl area.i

py/area.py py/area_wrap.c: area.c area.i
	swig -python -o py/area_wrap.c -outdir py area.i

java/areaJNI.java java/area.java java/area_wrap.c: area.c area.i 
	swig -java -outdir java -o java/area_wrap.c area.i 

java/area_wrap.o : java/areaJNI.java java/area.java java/area_wrap.c
	cd ./java ;$(CC) -c -fPIC -Dbool=char -D_GNU_SOURCE $(JAVA_OPTS) ../area.c area_wrap.c ;cd ../

pl/area_wrap.o : pl/area.pm pl/area_wrap.c
	cd ./pl;$(CC) -c -fPIC -Dbool=char -D_GNU_SOURCE $(PERL_OPTS) ../area.c area_wrap.c ;cd ../

py/area_wrap.o : py/area.py py/area_wrap.c
	cd ./py; $(CC) -c -fPIC -Dbool=char -D_GNU_SOURCE $(PYTHON_OPTS) ../area.c area_wrap.c; cd ../

py/_area.so : py/area_wrap.o
	cd ./py; $(CC) -shared -FPIC ../area.o ./area_wrap.o -o _area.so ; cd ../

java/libs/libarea.so : java/area_wrap.o
	cd ./java; $(CC) -shared -FPIC ../area.o ./area_wrap.o -o ./libs/libarea.so ; cd ../

area.class areaJNI.class JavaTest.class PrintLibraryPath.class: java/libs/libarea.so
	cd ./java; javac ./*.java; cd ../

pl/area.so : pl/area_wrap.o
	cd ./pl; $(CC) -shared -FPIC ../area.o ./area_wrap.o -o area.so ; cd ../

area.so : area.o 
#	$(CC) -shared -FPIC -Dbool=char $(PYTHON_OPTS) $(PERL_OPTS) area.o area_python_wrap.o area_perl_wrap.o -o area.so
	$(CC) -shared -FPIC area.o -o area.so

clean:
	find ./ -name "*.o" -delete 
	find ./ -name "*.so" -delete 
	rm -f py/area_wrap.c py/area.py pl/area_wrap.c pl/area.pm java/areaJNI.java java/area.java java/area_wrap.c
	rm -f area.class areaJNI.class JavaTest.class PrintLibraryPath.class
	rm -f area.java areaJNI.java 
