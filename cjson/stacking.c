/*
 * stacking.c
 *
 *  Created on: Mar 18, 2012
 *      Author: bryan
 */
#include<stdio.h>
#include "stacking.h"

void push(Stack *S, float val) {
	S->v[S->top] = val;
	(S->top)++;
	/*  Equivalent to: S->v[ (S->top)++ ] = val;   */
}

float pop(Stack *S) {
	(S->top)--;
	return (S->v[S->top]);
	/*  Equivalent to: return (S->v[--(S->top)]);  */
}

void init(Stack *S) {
	S->top = 0;
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
			printf("%g  ", S->v[i]);
		}
		printf("\n");
	}
}

