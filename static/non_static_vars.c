#include<stdio.h>

char** func_Str();

int main(void)
{
    char **ptr = NULL;

    ptr = func_Str();
    printf("\n [%s] \n",*ptr);

    return 0;
}

char** func_Str()
{
    char *p = "Linux";
    return &p;
}
