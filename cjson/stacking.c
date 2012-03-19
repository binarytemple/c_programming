/*
 * stacking.c
 *
 *  Created on: Mar 18, 2012
 *      Author: bryan
 */
#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<malloc.h>


#include "stacking.h"


void push(Stack *S, int val) {
	puts("pushing");
	S->top++;
	char * res = realloc(S->v[0], sizeof(int) * S->top);

	S->v[S->top] = val;


	//**( S-> v + (S->top *4))  = 1;
	//**((S-> v) +(S->top *4))= 1;
	//S->v = (float *)0;

	//S->&v + S->top] = &val;
	(S->top)++;
	if (S->top == 2000) {
		printf("should fail here!", stderr);
	}
	/*  Equivalent to: S->v[ (S->top)++ ] = val;   */
}

int pop(Stack *S) {

	printf("%d",sizeof(S->v));

	(S->top)--;
	char * res = realloc(S->v, sizeof(int) * S->top);

	return 0;//&(S->v[S->top])	            ;
	/*  Equivalent to: return (S->v[--(S->top)]);  */
}

void init(Stack *S) {
	S->top = 0;
	S->v = malloc(4);
}

int full(Stack *S) {
	return (S->top >= 20);
}

void MyStackPrint(Stack *S) {
	int i;
	if (S->top == 0)
		printf("Stack is empty.\n");
	else {
		printf("Stack contents: ");
		for (i = 0; i < S->top; i++) {
			printf("%d  ", S->v[i]);
		}
		printf("\n");
	}
}

