#include<stdio.h>
#include<limits.h>
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
	root->left->right = newNode(6);

	root->right->left = newNode(4);
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

int bst(struct tree *node, int min, int max)
{
	if(node == NULL)
		return 1;

	if(node->data < min || node->data > max)
		return 0;

	return bst(node->left, min, node->data) && bst(node->right, node->data, max);
}

int isBst(struct tree *node)
{

	return bst(node, INT_MIN, INT_MAX);
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
