/*	Write code that builds the following little 1-2-3 binary search tree by calling 
 *	insert() three times passing it the root pointer to build up the tree
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
struct node *insert(struct node *root,int data);

main()
{
	struct node *root=NULL;

	root=build123();
	print(root);
}

struct node *build123(void)
{
	struct node *root=NULL;

	root=insert(root,2);
	root=insert(root,1);
	root=insert(root,3);

	return root;

}

struct node *insert(struct node *root,int data)
{
	if(root == NULL)
		return newNode(data);
	else if(data<root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);

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
	printf("\n");
	if(root != NULL){
		print(root->left);
		printf("\t%d",root->data);
		print(root->right);
	}
	printf("\n");
}
