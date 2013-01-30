#include <stdio.h>

int main (int argc, char *argv[], char **env_var_ptr) {
    int i=0;
    printf("\ncmdline args count=%d", argc);

    /* First argument is executable name only */
    printf("\nexe name=%s", argv[0]);

    for (i=1; i< argc; i++) {
        printf("\narg%d=%s", i, argv[i]);
    }

    i=0;
    while (*env_var_ptr != NULL) {
        i++;
        printf ("\nenv var%d=>%s",i, *(env_var_ptr++));
    }

    printf("\n");
    return 0;
}
