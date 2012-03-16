#include<stdio.h> 

int main(void)
{
    char **ptr = NULL; 

    char *p = NULL; 

    char c = 'd'; 

    p = &c;
    ptr = &p; 

    printf("\n c = [%c]\n",c);
    printf("\n *p = [%c]\n",*p);
    printf("\n **ptr = [%c]\n",**ptr); 

    return 0;
}
