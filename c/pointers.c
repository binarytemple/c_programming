#include <stdio.h> 

int main(void)
{
  char ch = 'c';
  char *chptr = &ch; 

  int i = 20;
  int *intptr = &i; 

  float f = 1.20000;
  float *fptr = &f; 

  char *ptr = "I am a string"; 
  char *ptr2 = "t";
  char *ptr3 = "o";
  char *ptr4 = "o";

  printf("\n [%c], [%d], [%f], [%c], [%s], [%p]\n", *chptr, *intptr, *fptr, *ptr, ptr, &ptr);

  printf("\n [%p], [%p], [%p], [%p] \n", &ptr, &ptr2, &ptr3, &ptr4 ); 
  return 0;
}
