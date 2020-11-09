#include <stdio.h>

#include "tp03.h"

int main()
{
	root=NULL;
	int i=0;
	int arr[6]={20,30,40,50,25};
	int delArr[3]={40,20,25};
	root=insertAvl(root,10);
	

	for(i;i<5;i++)
	{
		insertAvl(root,arr[i]);
	}

	i=0;

	for(i;i<3;i++)
	{
		deleteNode(root,delArr[i]);
		printf("\n %d silindi... Post Order:",delArr[i]);
		printPostOrder(root);
		printf("  Pre Order:");
	       	printPreOrder(root);
		printf("  In Order:");
		printInOrder(root);
			

	}



	
}
