#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void count() {
	static int counter = 0;
	printf("count %d\n", counter);
	counter++;
}

int main(int argc, char *argv[]) {

	for (int i = 0; i < 10; ++i) {
		count();
	}
	return 0;
}
