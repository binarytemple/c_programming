#include<stdio.h> 

int main(void)
{
    char ch = 'c';
    char c = 'a'; 

    char *const ptr = &ch; // A constant pointer
    //Won't compile if following line is changed.
    //ptr = &c; // Trying to assign new address to a constant pointer. WRONG!!!! 

    return 0;
}
