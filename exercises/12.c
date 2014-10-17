/*	Suppose you are building an N node binary search tree with the values 1..N. How many structurally different
 *	binary search trees are there that store those values? Write a recursive function that, given the number of distinct
 *	values, computes the number of structurally unique binary search trees that store those values
 */

#include<stdio.h>

main()
{
	printf("\n\nenter N :");
	scanf("%d",&n);

	printf("\n\nthe number of structurally unique binary search trees that store ");
	for(i=1,i<=n;++i)
		printf("%d ",i);
	printf("is %d\n\n",countTrees(n));
}

int countTrees(int numKeys)
{
	if(numKeys <= 2)
		return numKeys;
	else{
		
