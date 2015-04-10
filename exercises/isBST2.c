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

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int maxVal(struct tree *node)
{
	if(node->left == NULL && node->right == NULL)
		return node->data;

	if(node->left == NULL)
		return node->right->data;
	if(node->right == NULL)
		return node->left->data;

	return max(maxVal(node->left), maxVal(node->right));
}

int minVal(struct tree *node)
{
	if(node->left == NULL && node->right == NULL)
		return node->data;

	if(node->left == NULL)
		return node->right->data;
	if(node->right == NULL)
		return node->left->data;

	return min(minVal(node->left), minVal(node->right));
}

int isBst(struct tree *node)
{
	if(node == NULL)
		return 1;

	if(node->left != NULL && maxVal(node->left) > node->data)
		return 0;

	if(node->right != NULL && minVal(node->right) <= node->data)
		return 0;

	return isBst(node->left) && isBst(node->right);
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
