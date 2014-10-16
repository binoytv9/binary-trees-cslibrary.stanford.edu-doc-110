/*	Given a binary tree and a sum, return true if the tree has a root-to-leaf path such that adding up all the values
 *	along the path equals the given sum. Return false if no such path can be found
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
int hasPathSum(struct node *node,int sum);
struct node *insert(struct node *root,int data);

main()
{
	int sum=3;
	struct node *root;

	root=build();

	printf("\n\n");
	print(root);
	printf("\n\n");

	if(hasPathSum(root,sum))
		printf("\n\n\tTrue : tree has a root-to-leaf path with PathSum of %d\n\n",sum);
	else
		printf("\n\n\tFalse : tree does not have a root-to-leaf path with PathSum of %d\n\n",sum);

}

int hasPathSum(struct node *node,int sum)
{
	int fl,fr;

	if(node == NULL){
		if(sum == 0)
			return 1;
		else
			return 0;
	}
	else{
		fl=hasPathSum(node->left,sum-(node->data));
		fr=hasPathSum(node->right,sum-(node->data));
	}

	return fl || fr;
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
