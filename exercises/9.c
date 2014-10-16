/*	Change a tree so that the roles of the left and right pointers are swapped at every node	*/


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *build(void);
void print(struct node *root);
void mirror(struct node *node);
struct node *insert(struct node *node,int data);

main()
{
	struct node *root=build();

	printf("\n\n");
	print(root);
	printf("\n\n");

	mirror(root);

	printf("\n\n");
	print(root);
	printf("\n\n");
}

void mirror(struct node *node)
{
	struct node *tmp;

	if(node != NULL){
		tmp=node->left;
		node->left=node->right;
		node->right=tmp;

		mirror(node->left);
		mirror(node->right);
	}
}

struct node *build(void)
{
	int i,len;
	int a[]={4,2,5,1,3};
	struct node *root = NULL;

	len=sizeof(a)/sizeof(int);

	for(i=0;i<len;++i)
		root=insert(root,a[i]);

	return root;
}



struct node *insert(struct node *node,int data)
{
	struct node *new;

	if(node == NULL){
		new=malloc(sizeof(*new));
		new->data=data;
		new->right=new->left=NULL;

		return new;
	}
	else if(data<node->data)
		node->left=insert(node->left,data);
	else
		node->right=insert(node->right,data);

	return node;
}

void print(struct node *node)
{
	if(node != NULL){
		print(node->left);
		printf("\t%d",node->data);
		print(node->right);
	}
}
