/*	Given two binary trees, return true if they are structurally identical -- they are made of nodes with the same values
 *	arranged in the same way
 */



#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void print(struct node *node);
struct node *newNode(int data);
void doubleTree(struct node *node);
struct node *build(int a[],int len);
struct node *insert(struct node *root,int data);

main()
{
	int len;
	int d1[]={2,1,3};
	int d2[]={2,1,3};
	struct node *a,*b;

	len=sizeof(d1)/sizeof(int);
	a=build(d1,len);
	len=sizeof(d2)/sizeof(int);
	b=build(d2,len);

	printf("\nTree A :\n");
	print(a);
	printf("\n\n");
	printf("\nTree B :\n");
	print(b);
	printf("\n\n");

	if(sameTree(a,b))
		printf("\n\n\t\tTrue : both Tree A and B are same\n\n");
	else
		printf("\n\n\t\tFalse : both Tree A and B are not same\n\n");

}

int sameTree(struct node *a,struct node *b)
{
	int fl,fr;

	if(a == NULL && b == NULL)
		return 1;
	else if((a == NULL && b != NULL) || (a != NULL && b == NULL))
		return 0;

	if(a->data == b->data){
			fl = sameTree(a->left,b->left);
			fr = sameTree(a->right,b->right);
	}
	else
		return 0;

	return fl && fr;
}

struct node *build(int a[],int len)
{
	int i;
	struct node *root=NULL;

	for(i=0;i<len;++i)
		root=insert(root,a[i]);

	return root;
}

struct node *insert(struct node *root,int data)
{
	if(root == NULL)
		return newNode(data);
	else if(data < root->data)
		root->left = insert(root->left,data);
	else
		root->right = insert(root->right,data);

	return root;
}

struct node *newNode(int data)
{
	struct node *new=malloc(sizeof(*new));

	new->data=data;
	new->right=new->left=NULL;

	return new;
}

void print(struct node *node)
{
	if(node != NULL){
		print(node->left);
		printf("\t%d",node->data);
		print(node->right);
	}
}
