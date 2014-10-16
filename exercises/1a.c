/*	Write code that builds the following little 1-2-3 binary search tree by calling 
 *	newNode() three times, and using three pointer variables
 */


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *build123(void);
void print(struct node *root);
struct node *newNode(int data);

main()
{
	struct node *root=NULL;

	root=build123();
	print(root);
}

struct node *build123(void)
{
	struct node *first,*second,*third;

	first=newNode(2);
	second=newNode(1);
	third=newNode(3);

	first->right=third;
	first->left=second;

	return first;
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
	printf("\n");
	if(root != NULL){
		print(root->left);
		printf("\t%d",root->data);
		print(root->right);
	}
	printf("\n");
}
