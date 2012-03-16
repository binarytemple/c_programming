#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int populate_data(char * data) {
	int length = 100;
	char * blah = "populated and memcopied, beatch..\n\0";
	char * res = realloc(data, length * sizeof(char));
	memcpy(data, blah, length);
	return length;
}

int main(int argc, char **argv) {
	char * data = malloc(1);
	char * realloc_res1 = (char*) realloc(data, 200);
	printf("%s\n", data);

	char * data2 = malloc(4);
	populate_data(data2);

	printf("%s\n", data2);
}
