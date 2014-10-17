/*	Write an isBST() function that returns true if a tree is a binary search tree
 *	and false otherwise
 */


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *build(void);
int isBST(struct node *node);
void print(struct node *root);
struct node *insert(struct node *root,int data);


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

	if(isBST(root))
		printf("\n\n\tBST\n\n");
	else
		printf("\n\n\tnot BST\n\n");
		

}

int isBST(struct node *node)
{
	int fl,fr;

	fl=fr=1;

	if(node == NULL)
		return 1;

	if(node->left != NULL)
		if(node->left->data > node->data)
			return 0;
	if(node->right != NULL)
		if(node->right->data <= node->data)
			return 0;

	fl=isBST(node->left);
	fr=isBST(node->right);

	return fl && fr;
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
	else if(data <= root->data)
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
