#include <stdio.h>
#include "tp03.h"



struct AvlNode* insertAvl(struct AvlNode *p,int data)
{
	struct AvlNode* avlNode;
	if(!p)
	{
		avlNode =  (struct AvlNode*)malloc(sizeof(struct AvlNode));
		avlNode->data=data;
		avlNode->leftChild=NULL;
		avlNode->rightChild=NULL;
		avlNode->height=1;
		return avlNode;
	}

	if(data < p->data)
	{
		p->leftChild=insertAvl(p->leftChild,data);
	}
	else if(data > p->data)
	{
		p->rightChild=insertAvl(p->rightChild,data);
	}

	p->height = getHeight(p);

	return p;



}

int getHeight(struct avlNode *p)
{
	int hLeftSub,hrightSub;
	hLeftSub=p && p->leftChild?p->leftChild->height:0;
	hrightSub=p && p->rightChild?p->rightChild->height:0;
	return hleftSub>hrightSub?hleftSub+1:hrightSub+1;
}


