/*	Given a binary tree, count the number of nodes in the tree	*/


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *build(void);
int size(struct node *root);
void print(struct node *root);
struct node *insert(struct node *root,int data);

main()
{
	struct node *root;

	root=build();

	print(root);
	printf("\n\nno of nodes is %d\n\n",size(root));
}

int size(struct node *root)
{
	if(root == NULL)
		return 0;

	return 1 + size(root->left) + size(root->right);
}

struct node *build(void)
{
	int i,len;
	int a[]={1,5,7,9,3,2,6,9,6,0,8,0,9,5,3};
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
