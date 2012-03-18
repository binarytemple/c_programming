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
	float v[20];
	int top;
} Stack;

void push(Stack *S, float val);
float pop(Stack *S);
void init(Stack *S);
int full(Stack *S);
void MyStackPrint(Stack *S);

#endif /* STACKING_H_ */
