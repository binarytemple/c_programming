#include<stdlib.h>
#include<stdio.h>

typedef struct {
	int house_number;
	char * street;
	char * town;
	char postcode_1[3];
	char postcode_2[3];
} mail_address;

typedef struct {
	int id;
    mail_address * data;
} insertible;

typedef struct  {
	int id;
    int * id_pointer;
	mail_address * data;
	struct bin_tree * right;
	struct bin_tree * left;
} bin_tree;


void insert(bin_tree ** tree, insertible * val) {
//	int target = val->id;
//	printf("target val %d\n",target);
//	printf("data address %d\n",val->data);
//
//	bin_tree *temp = NULL;
//	if (!(*tree)) {
//		temp = (bin_tree *) malloc(sizeof(bin_tree));
//		temp->left  = temp->right = NULL;
//		temp->id = target;
//		*tree = temp;
//		return;
//	}
//
//	if (target < (*tree)->id) {
//		insert((*tree)->left, val);
//	} else if (target > (*tree)->id) {
//		insert((*tree)->right, val);
//	}

}

void main() {

bin_tree * t = malloc(sizeof(bin_tree)); 
t->id = 10;

mail_address * ma = malloc(sizeof(mail_address));
ma->house_number = 10;
t->data = ma;


printf("bin_tree %d\n", t->id);
printf("bin_tree address 0 %d\n", t[0]);
printf("bin_tree address 1 %d\n", t[1]);
printf("bin_tree address t->id %d\n", &(t->id));

printf("bin_tree address deref 0 %d\n", &(t[0]));
printf("bin_tree address deref 1 %d\n", &(t[1]));


printf("house number %d\n", t->data->house_number);

	//insert(&root, mk_ins(2,NULL) );
}
