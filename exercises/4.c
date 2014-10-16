/*	Given a non-empty binary search tree (an ordered binary tree), return the minimum data value found in that tree.
 *	Note that it is not necessary to search the entire tree.
 */



#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *build(void);
int minValue(struct node *root);
void print(struct node *root);
struct node *insert(struct node *root,int data);

main()
{
	struct node *root;

	root=build();

	print(root);
	printf("\n\nminimum datavalue is %d\n\n",minValue(root));
}

int minValue(struct node *root)
{
	if(root->left == NULL)
		return root->data;

	minValue(root->left);
}

struct node *build(void)
{
	int i,len;
	int a[]={11,5,7,9,3,2,6,9,6,10,8,20,9,5,3};
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
