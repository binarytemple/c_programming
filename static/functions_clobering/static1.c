// static_1.c

#include<stdio.h>

void funcNew();

int func(void)
{
    funcNew();
    return 0;
}

void funcNew()
{
    printf("\n Hi, I am a normal function\n");
}
