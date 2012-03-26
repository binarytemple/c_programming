CC = g++ -ggdb
#List all 'c' files by wildcard.
SOURCES=$(wildcard *.cpp)
#Get the 'exe' equivalent of said file
EXECUTABLES=$(SOURCES:%.cpp=%)
#ARGS=`mysql_config --cflags --libs && pkg-config --cflags --libs gtk+-2.0 && pkg-config --cflags --libs sdl`  
ARGS=-lpthread

all: $(EXECUTABLES)
.PHONY: all
$(EXECUTABLES): % : %.cpp
	$(CC) $< -o $@ $(ARGS)

.PHONY clean:
clean:
	find ./ -type f -executable -delete 

rebuild: clean all
