#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct blob_n_len {
	char * data;
	int length;
};

struct mystruct {
	int x, y;
	char hello[6];
} mystruct = { 1, 2, "howdy" };

int main(int argc, char *argv[]) {
	mystruct.x += 2;
	return 0;
}
