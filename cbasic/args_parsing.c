#include <stdio.h>

int main (int argc, char *argv[]) {
    int i=0;
    printf("\nargs count : %d", argc);


    printf("\nexecutable : %s", argv[0]);

    for (i=1; i< argc; i++) {
        printf("\nargument %d : %s", i, argv[i]);
    }

    printf("\n");

    return 0;
}
