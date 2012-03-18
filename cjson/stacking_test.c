/*
 * stacking.c
 *
 *  Created on: Mar 18, 2012
 *      Author: bryan
 */

#include<stdio.h>
#include "stacking.h"

int
main(int argc, char ** argv)
{
	Stack S;

	init(&S);

	MyStackPrint(&S);

	push(&S, 2.31);
	push(&S, 1.19);

	MyStackPrint(&S);

	printf("Popped value is: %g\n", pop(&S));

	push(&S, 6.7);

	MyStackPrint(&S);

	push(&S, pop(&S) + pop(&S));

	MyStackPrint(&S);
}

