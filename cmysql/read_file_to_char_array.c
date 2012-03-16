/*
 * read_file_to_char_array.c
 *
 *  Created on: Mar 14, 2012
 *      Author: bryan
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	unsigned long *lengths;
	FILE *fp;
	struct stat sb;

	fp = fopen("image.png", "rb");

	int fd = fileno(fp);

	fstat(fd, &sb);

	size_t size = sb.st_size;
	printf(" Size - %ld : ", (long unsigned int) size);

	//	char data [size] ;
	char * data;
	data = malloc(size * sizeof(char));
	fread(data, size, 1, fp);
	fclose(fp);

}
