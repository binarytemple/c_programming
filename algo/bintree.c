#include<stdlib.h>
#include<stdio.h>

typedef struct {
	int house_number;
	char * street;
	char * town;
	char * postcode;

} mail_address;

typedef struct {
	int id;
	mail_address * data;
} insertible;

struct bin_tree_s {
	int id;
	mail_address * data;
	struct bin_tree_s * right;
	struct bin_tree_s *left;
};

typedef struct bin_tree_s bin_tree;

//&(insertible){ .id = X, .data =   &(mail_address){.house_number = H,->street = S, ->town=T, ->postcode =P 	 }}

#define mk_ins(X, H,S,T,P) &(insertible){.id = X, .data =     &(mail_address ) { .house_number = H, .street = \
			((char*) S), .town = ((char*) T), .postcode = \
			((char*) P) } }

//#define MK_ADDRESS() &(mail_address){	.house_number=H ,	.street = ((char*)S) ,	.town = ((char*)T)   ,	.postcode = ((char*)P)}

//		 .house_number = H,
//		 -> street =S;
//		 	town -> T
//		 	postcode -> P
void insert(bin_tree ** tree, insertible * val) {
	int target = val->id;
	printf("target val %d\n", target);
	printf("data address %d\n", val->data);

	bin_tree *temp = NULL;
	if (!tree) {
		temp = malloc(sizeof(bin_tree));
		temp->left = temp->right = NULL;
		temp->id = &target;
		tree = &(*temp);
		return;
	}

	if (target < (*tree)->id) {
		insert(&(*tree)->left, val);
	} else if (target > (*tree)->id) {
		insert(&(*tree)->right, val);
	}

}

void print_preorder(bin_tree * tree) {
	if (tree) {
		printf("%d\n", tree->id);
		print_preorder(tree->left);
		print_preorder(tree->right);
	}

}
//
//void print_inorder(bin_tree * tree) {
//	if (tree) {
//		print_inorder(tree->left);
//		printf("%d\n", tree->id);
//		print_inorder(tree->right);
//	}
//}

void print_postorder(bin_tree * tree) {
	if (tree) {
		print_postorder(tree->left);
		print_postorder(tree->right);
		printf("%d\n", tree->id);
	}
}

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
	bin_tree **root;
	bin_tree ** tmp;

	root = NULL;
//
//	mail_address d = { 10, "s", "t", "p" }; //= mk_address(10,"s","t","t");
//
//	mail_address mad = (mail_address ) { .house_number = 10, .street =
//					((char*) "street"), .town = ((char*) "town"), .postcode =
//					((char*) "postcode") };
	/* Insert bin_trees into tree */
//	insert(&root, mk_ins(9,&mad ));
	//insert(&root, mk_ins(4, 1,"billybegs street","dunmore","D13P45");

//	insertible * i;
//	//i = &(insertible){.id = 4, .data =  (mail_address){.house_number = 1,->street = "billybegs street", ->town="dunmore", ->postcode ="D13P45" 	 }};
//	//i = &(insertible){.id = 4, .data =  &mad};
//	i = &(insertible ) { .id = 4, .data =
//					&(mail_address ) { .house_number = 10, .street =
//									((char*) "street"),
//									.town = ((char*) "town"), .postcode =
//											((char*) "postcode") } };

	insert(root, mk_ins(4,4,"street","town","postcode"));
	insert(root, mk_ins(15,15,"street","town","postcode"));
	insert(root, mk_ins(6,6,"street","town","postcode"));
	insert(root, mk_ins(12,12,"street","town","postcode"));
	insert(root, mk_ins(17,17,"street","town","postcode"));
	insert(root, mk_ins(2,2,"street","town","postcode"));
//
//
//
//
//	));
//			insert(&root, mk_ins(6,NULL));
//			insert(&root, mk_ins(12,NULL));
//			insert(&root, mk_ins(17,NULL));
//			insert(&root, mk_ins(2,NULL));
//
//	/* Printing nodes of tree */
//	printf("Pre Order Display\n");
//	print_preorder(root);
//
//	printf("In Order Display\n");
//	print_inorder(root);
//
	printf("Post Order Display\n");
	print_postorder(root);
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
