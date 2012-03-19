#include<stdlib.h>
#include<stdio.h>

struct list_el {
	int val;
	struct list_el * next;
	struct list_el * prev;
};

typedef struct list_el item;

void main() {
	item * curr, *head;
	int i;

	head = NULL;

	for (i = 1; i <= 10; i++) {
		curr = (item *) malloc(sizeof(item));
		curr->val = i;
		curr->next = head;
		head->prev = curr;
		head = curr;
	}

	curr = head;

	while (curr) {
		printf("%d\n", curr->val);
		curr = curr->next;
	}



	//cleanup









}
