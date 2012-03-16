#include<stdio.h> 

int main(void)
{
    char ch = 'c';
    const char *ptr = &ch; // A constant pointer 'ptr' pointing to 'ch'
    //*ptr = 'a';// WRONG!!! Cannot change the value at address pointed by 'ptr'. 

    return 0;
}
