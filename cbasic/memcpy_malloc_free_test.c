#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#undef DEBUG_MEM

int main(int argc, char **argv) {

	char * data = "hello nick and dave";

	int len = strlen(data);

	for (int up = 1; up <= len; ++up) {

#ifdef DEBUG_MEM
		for (int j = 0; j < 200; ++j) {
			printf("%x \n", (int) *(data - j));
		}
#endif

		char * tmp = malloc(up + 1);
		*(tmp + (up + 1)) = '\0';
		memcpy(tmp, data, up);
		printf("%s up %d \n", tmp, up);

#ifndef DONT_FREE_MEM
		free(tmp);
#endif

	}
}
