/*	Given a binary tree, print out the nodes of the tree according to a bottom-up "postorder" traversal -- both subtrees of
 *	a node are printed out completely before the node itself is printed, and each left subtree is printed before the right
 *	subtree. So the tree...
 *	    4
 *	   / \
 *	  2   5		produces output "1 3 2 5 4"
 *	 / \
 *	1  3
 */



#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *build(void);
void print(struct node *root);
void printPostorder(struct node *node);
struct node *insert(struct node *root,int data);

main()
{
	struct node *root;

	root=build();

	printf("\n\n");
	print(root);
	printf("\n\n");

	printf("\npost order output is :\n");
	printPostorder(root);
	printf("\n\n");
}

void printPostorder(struct node *node)
{
	if(node != NULL){
		printPostorder(node->left);
		printPostorder(node->right);
		printf("\t%d",node->data);
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
