
// static_1.c

#include<stdio.h>

static int count = 4;

int func(void)
{
    printf("\n count = [%d]\n",count);
    return 0;
}
