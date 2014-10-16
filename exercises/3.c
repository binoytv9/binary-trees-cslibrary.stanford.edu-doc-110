/*	Given a binary tree, compute its "maxDepth" -- the number of nodes along the longest path from the root node down
 *	to the farthest leaf node
 *
 *			  4
 *		       /     \
 *		      2       5
 *		    /   \    / \
 *		   1     3  4   7
 *			       / \
 *			      6   8
 *				   \
 *				    9
 */


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *build(void);
void print(struct node *root);
int maxDepth(struct node *node);
struct node *insert(struct node *root,int data);

main()
{
	struct node *root;

	root=build();

	printf("\n\n");
	print(root);
	printf("\n\n");

	printf("\nmaxm depth is : %d\n\n",maxDepth(root));
}

int maxDepth(struct node *node)
{
	int l,r;

	l=r=1;

	if(node == NULL)
		return 0;

	if(node->left != NULL)
		l = 1 + maxDepth(node->left);
	if(node->right != NULL)
		r = 1 + maxDepth(node->right);

	return l>=r ? l : r;
}

struct node *build(void)
{
	int i,len;
	int a[]={4,2,5,1,3,4,7,8,6,9};
	struct node *root=NULL;

	len=sizeof(a)/sizeof(int);

	for(i=0;i<len;++i)
		root=insert(root,a[i]);

	return root;
}

struct node *insert(struct node *root,int data)
{
	if(root == NULL){
		root=malloc(sizeof(*root));
		root->data=data;
		root->right=root->left=NULL;
	}
	else if(data < root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);

	return root;
}

void print(struct node *root)
{
	if(root != NULL){
		print(root->left);
		printf("\t%d",root->data);
		print(root->right);
	}
}
