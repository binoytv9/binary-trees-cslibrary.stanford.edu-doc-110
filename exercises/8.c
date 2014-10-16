/*	Given a binary tree, print out all of its root-to-leaf paths, one per line	*/




#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *build(void);
void print(struct node *root);
void printPaths(struct node *node);
struct node *insert(struct node *root,int data);

main()
{
	int sum=3;
	struct node *root;

	root=build();

//	printf("\n\n");
//	print(root);
//	printf("\n\n");

	printPaths(root);

}

void printPaths(struct node *node)
{
	if(node == NULL){
		printf("\n");
		return;
	}
	else{
		printf("\t%d",node->data);
		printPaths(node->left);
		printPaths(node->right);
	}
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

void print(struct node *root)
{
	if(root != NULL){
		print(root->left);
		printf("\t%d",root->data);
		print(root->right);
	}
}
