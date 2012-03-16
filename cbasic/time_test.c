#include <stdio.h>
#include <time.h>
int main() {
	time_t sec = time(NULL);
	char * t = ctime(&sec);
	printf("The date is: %s", t);

	printf("Number of hours since January 1, 1970 is %ld \n", sec / 3600);

	struct tm * ptm = gmtime(&sec);

	//Structure pointer dereferencing.
	int year = ptm->tm_year + 1900;

	printf("The year is: %d", year);
	return 0;
}

