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

typedef struct {
	int id;
	mail_address * data;
	struct bin_tree * right, *left;
} bin_tree;


//#define mk_ins(X, Y) &(*(insertible){ .id = X, .mail_address = Y })

void insert(bin_tree ** tree, insertible * val) {
	int target = val->id;
	printf("target val %d",target);
	printf("data address %d",val->data);

	bin_tree *temp = NULL;
	if (!(*tree)) {
		temp = (bin_tree *) malloc(sizeof(bin_tree));
		temp->left = temp->right = NULL;
		temp->id = target;
		*tree = temp;
		return;
	}

//	if (target < (*tree)->id) {
//		insert(&(*tree)->left, val);
//	} else if (target > (*tree)->id) {
//		insert(&(*tree)->right, val);
//	}

}

//void print_preorder(bin_tree * tree) {
//	if (tree) {
//		printf("%d\n", tree->id);
//		print_preorder(tree->left);
//		print_preorder(tree->right);
//	}
//
//}
//
//void print_inorder(bin_tree * tree) {
//	if (tree) {
//		print_inorder(tree->left);
//		printf("%d\n", tree->id);
//		print_inorder(tree->right);
//	}
//}
//
//void print_postorder(bin_tree * tree) {
//	if (tree) {
//		print_postorder(tree->left);
//		print_postorder(tree->right);
//		printf("%d\n", tree->id);
//	}
//}
//
//void deltree(bin_tree * tree) {
//	if (tree) {
//		deltree(tree->left);
//		deltree(tree->right);
//		free(tree);
//	}
//}
//
//void fail(char * msg) {
//	printf(msg);
//	exit(1);
//}
//
//bin_tree* search(bin_tree ** tree, insertible * val) {
//	int target = val->id;
//	if (!(*tree)) {
//		return NULL ;
//	}
//	if (target < (*tree)->id) {
//		return search(&((*tree)->left), val);
//	} else if (target > (*tree)->id) {
//		return search(&((*tree)->right), val);
//	} else if (target == (*tree)->id) {
//		return *tree;
//	} else {
//		fail("uncorrect situation");
//		return NULL ;
//	}
//}

/**
 * This is code to demonstrate the use of the binary tree
 * id structure.
 *
 * http://en.wikipedia.org/wiki/Binary_tree
 *
 *
 * This code will not create a balanced binary tree.
 * Meaning that particular combinations of inserted values 
 * can result in excessivly long retrieval times.
 *
 * In order to create a balanced binary tree, it is necessary 
 * to create what is known as a red-black tree.
 *
 * http://en.wikipedia.org/wiki/Red-black_tree
 *
 */
void main() {
	bin_tree *root;
	bin_tree *tmp;

	root = NULL;




	insertible a;
	a.id = 9 ;
//a->data  = &NULL ;

//	  insertible a = (insertible){ .id = 9, .mail_address = NULL };

	/* Insert bin_trees into tree */
insert(&root, &a);
//	insert(&root, mk_ins(4,NULL) );
//	insert(&root, mk_ins(15,NULL) );
//	insert(&root, mk_ins(6,NULL) );
//	insert(&root, mk_ins(12,NULL) );
//	insert(&root, mk_ins(17,NULL) );
//	insert(&root, mk_ins(2,NULL) );
//
//	/* Printing nodes of tree */
//	printf("Pre Order Display\n");
//	print_preorder(root);
//
//	printf("In Order Display\n");
//	print_inorder(root);
//
//	printf("Post Order Display\n");
//	print_postorder(root);
//
//	/* Search nodes into tree */
//	tmp = search(&root, 4);
//	if (tmp) {
//		printf("Searched bin_tree=%d\n", tmp->id);
//	} else {
//		printf("id Not found in tree.\n");
//	}
//
//	/* Deleting all nodes of tree */
//	deltree(root);
}
