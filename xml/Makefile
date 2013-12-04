CC=gcc

all: xmlkv

xmlkv: xmlkv.c
	# compiling keyword sample
	$(CC) -o $@ $< `xml2-config --cflags --libs`

clean:
	rm -rf xmlkv
