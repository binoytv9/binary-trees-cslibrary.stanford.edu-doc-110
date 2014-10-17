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
struct node *insert(struct node *root,int data);
void printPaths(struct node *node,int path[],int pathLen);


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

	printf("root-to-leaf paths are :\n\n");
	printPaths(root,path,pathLen);
	printf("\n\n");

}

void printPaths(struct node *node,int *path,int pathLen)
{
	int i;

	if(node == NULL){
		printf("\n");
		return;
	}
	else{
		*(path+pathLen) = node->data;
		pathLen++;

		if(node->left == NULL && node->right == NULL)
			for(i=0;i<pathLen;++i)
				printf("\t%d",path[i]);

		printPaths(node->left,path,pathLen);
		printPaths(node->right,path,pathLen);
	}
}

struct node *build(void)
{
	int i,len;
	int a[]={5,3,1,4,9,6,11,10,15};
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
