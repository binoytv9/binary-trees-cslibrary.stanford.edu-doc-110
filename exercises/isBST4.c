#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree *newNode(int data)
{
	struct tree *new = malloc(sizeof(struct tree));

	new->data = data;
	new->left = new->right = NULL;

	return new;
}

struct tree *buildTree(void)
{
	struct tree *root = newNode(5);

	root->left = newNode(2);
	root->right = newNode(7);

	root->left->left = newNode(1);
	root->left->right = newNode(3);

	root->right->left = newNode(6);
	root->right->right = newNode(400);

	return root;
}

void printTree(struct tree *node)
{
	if(node != NULL){
		printTree(node->left);
		printf("%d ", node->data);
		printTree(node->right);
	}
}

int bst(struct tree *node, struct tree **nextRef)
{
	if(node == NULL)
		return 1;

	if(!bst(node->left, nextRef))
		return 0;

	if(*nextRef != NULL && node->data < (*nextRef)->data)
		return 0;

	*nextRef = node;

	return bst(node->right, nextRef);
}

int isBst(struct tree *node)
{

	struct tree *prev = NULL;
	return bst(node, &prev);
}

main()
{
	struct tree *root;

	root = buildTree();

	printf("tree is...\n");
	printTree(root);
	printf("\n");

	printf("checking tree... ");
	if(isBst(root))
		printf("BST!!!\n");
	else
		printf("not BST!!!\n");
}
