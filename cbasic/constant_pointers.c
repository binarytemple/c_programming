#include<stdio.h>

int main(void)
{
    int var1 = 0,var2 = 0;
    const int* const ptr = &var1;
    /*
     * If the following two lines are changed,
     * the program will refuse to compile.
     * const prevents variables from being modified.
     * (the variable could still be clobbered by direct memory access)
     */
    //*ptr = 1;
    //ptr = &var2;
    printf("%d\n", *ptr);

    return 0;
}
