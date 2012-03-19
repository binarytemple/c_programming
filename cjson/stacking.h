/*
 * stacking.h
 *
 *  Created on: Mar 18, 2012
 *      Author: bryan
 */

#ifndef STACKING_H_
#define STACKING_H_

/* mystack.h -- Stack declaration and function prototypes:  */

typedef struct {
	int ** v ;
	int top;
} Stack;

void push(Stack *S, int val);
int pop(Stack *S);
void init(Stack *S);
int full(Stack *S);
void MyStackPrint(Stack *S);

#endif /* STACKING_H_ */
