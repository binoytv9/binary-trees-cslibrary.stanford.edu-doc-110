/*	Write an isBST() function that returns true if a tree is a binary search tree
 *	and false otherwise
 */


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *build(void);
int isBST(struct node *node);
void print(struct node *root);
struct node *newNode(int data);

main()
{
	int sum=3;
	int pathLen=0;
	int path[100];
	struct node *root;

	root=build();

	printf("\n\n");
	print(root);
	printf("\n\n");

	if(isBST(root))
		printf("\n\n\tBST\n\n");
	else
		printf("\n\n\tnot BST\n\n");
		

}

int isBST(struct node *node)
{
	if(node == NULL)
		return 1;

	if(node->left != NULL)
		if(node->left->data > node->data)
			return 0;
	if(node->right != NULL)
		if(node->right->data <= node->data)
			return 0;

	return isBST(node->left) && isBST(node->right);
}

struct node *build(void)
{
	int i,len;
	struct node *root=NULL;

	root=newNode(5);			/*		5		*/
	root->left=newNode(2);			/*	      /    \		*/
	root->right=newNode(7);			/*	     2      7		*/
	root->left->left=newNode(1);		/*	    / \	   / \		*/
	root->left->right=newNode(6);		/*	   1   6  4   400	*/
	root->right->left=newNode(4);		
	root->right->right=newNode(400);

	return root;
}

struct node *newNode(int data)
{
	struct node *new=malloc(sizeof(*new));

	new->data=data;
	new->right=new->left=NULL;

	return new;
}

void print(struct node *root)
{
	if(root != NULL){
		print(root->left);
		printf("\t%d",root->data);
		print(root->right);
	}
}
