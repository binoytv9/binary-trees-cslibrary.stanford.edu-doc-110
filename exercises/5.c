/*	Given a binary search tree (aka an "ordered binary tree"), iterate over 
 *	the nodes to print them out in increasing order
 */


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *build(void);
void printTree(struct node *root);
struct node *insert(struct node *root,int data);

main()
{
	struct node *root;

	root=build();

	printf("\n\n");
	printTree(root);
	printf("\n\n");
}

struct node *build(void)
{
	int i,len;
	int a[]={4,2,5,1,3};
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

void printTree(struct node *root)
{
	if(root != null){
		printTree(root->left);
		printf("\t%d",root->data);
		printTree(root->right);
	}
}
