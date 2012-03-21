#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char * greeting() {
	return "function returning pointer";
}
void init_greeting(char ** pointer) {
	char * news = "strength of ten!";
	char * tmp = malloc(strlen(*pointer));
	char * res = strcpy(tmp, *pointer);
	(*pointer) = news;
}

int main(int argc, char **argv) {
	printf("%s\n", greeting());
	char * message = "the darling buds of may";
	printf("The message was: %s\n", message);
	init_greeting(&message);
	printf("The message is now: %s\n", message);
}
