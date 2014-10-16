/*	For each node in a binary search tree, create a new duplicate node, and insert the duplicate as the left child of the
 *	original node. The resulting tree should still be a binary search tree
 */


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *build(void);
void print(struct node *node);
struct node *newNode(int data);
void doubleTree(struct node *node);
struct node *insert(struct node *root,int data);

main()
{
	struct node *root=build();

	printf("\n\n");
	print(root);
	printf("\n\n");

	doubleTree(root);

	printf("\n\n");
	print(root);
	printf("\n\n");
}

void doubleTree(struct node *node)
{
	struct node *new;

	if(node != NULL){
		new=newNode(node->data);
		new->left=node->left;
		node->left=new;

		doubleTree(new->left);
		doubleTree(node->right);
	}
		
	
}

struct node *build(void)
{
	int i,len;
	int a[]={2,1,3};
	struct node *root=NULL;

	len=sizeof(a)/sizeof(int);

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
