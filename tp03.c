#include <stdio.h>
#include <stdlib.h>
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
	

	if(getBalance(p)==2 && getBalance(p->leftChild)==1)
	{
		return LLRotate(p);
	}
	else if(getBalance(p)==2 && (getBalance(p->leftChild)==-1 || getBalance(p->leftChild)==0))
	{
		
		return LRRotate(p);
	}
	else if(getBalance(p)==-2 && getBalance(p->rightChild)==-1)
	{
		
		return RRRotate(p);
	}
	else if(getBalance(p)==-2 && (getBalance(p->rightChild)==1 || getBalance(p->rightChild)==0))
	{
		return RLRotate(p);
	}




	return p;



}

int getHeight(struct AvlNode *p)
{
	int hLeftSub,hRightSub;
	hLeftSub=p && p->leftChild?p->leftChild->height:0;
	hRightSub=p && p->rightChild?p->rightChild->height:0;
	return hLeftSub>hRightSub?hLeftSub+1:hRightSub+1;
}

int getBalance(struct AvlNode *p)
{

	int hLeftSub,hRightSub;
	hLeftSub=p && p->leftChild?p->leftChild->height:0;
	hRightSub=p && p->rightChild?p->rightChild->height:0;
	return hLeftSub-hRightSub;
		
}

struct AvlNode* LLRotate(struct AvlNode *p)
{
	struct AvlNode *pLeftChild = p->leftChild;
	struct AvlNode *pRightChild = p->rightChild;
	pLeftChild->rightChild=p;
	p->leftChild=pRightChild;

	p->height=getHeight(p);
	pLeftChild->height=getHeight(pLeftChild);
	if(root==p)
		root=pLeftChild;
	return pLeftChild;
}

struct AvlNode* RLRotate(struct AvlNode *p)
{

	
	struct AvlNode* pRight=p->rightChild;
	struct AvlNode* pRightLeft=pRight->leftChild;

	p->rightChild=pRightLeft->leftChild;
	pRight->leftChild=pRightLeft->rightChild;
	pRightLeft->rightChild=pRight;
	pRightLeft->leftChild=p;

	p->height=getHeight(p);
	pRight->height=getHeight(pRight);
	pRightLeft->height=getHeight(pRightLeft);

	if(root==p)
	{
		root=pRightLeft;
	}
	return pRightLeft;

}

struct AvlNode* RRRotate(struct AvlNode *p)
{

	struct AvlNode* pRightChild=p->rightChild;
	
	p->rightChild=pRightChild->leftChild;
	pRightChild->leftChild=p;
	p->height=getHeight(p);
	pRightChild->height=getHeight(pRightChild);

	if(p==root)
		root=pRightChild;
	return pRightChild;
}

struct AvlNode* LRRotate(struct AvlNode *p)
{

	struct AvlNode *pLeft = p->leftChild;
	struct AvlNode *pLeftRight = pLeft->rightChild;

	pLeft->rightChild=pLeftRight->leftChild;
	p->leftChild=pLeftRight->rightChild;
	pLeftRight->leftChild=pLeft;
	pLeftRight->rightChild=p;

	p->height=getHeight(p);
	pLeft->height=getHeight(pLeft);
	pLeftRight->height=getHeight(pLeftRight);
	
	if(root==p)
	{
		root=pLeftRight;
	}

	return pLeftRight;
}

struct AvlNode* deleteNode(struct AvlNode* p,int data)
{


	struct AvlNode* q;

	if(p==NULL)
	{
		return NULL;
		
	}

	if(p->leftChild==NULL && p->rightChild==NULL && data==p->data)
	{
		if(p==root)
		{
			printf("evet root esittir head");
			root=NULL;


		}
			
		free(p);
		return NULL;
	}



	if(p->data==data)
	{
	



		if(treeHeight(p->leftChild) > treeHeight(p->rightChild))
		{
			q=findMax(p->leftChild);
			p->data=q->data;
			p->leftChild=deleteNode(p->leftChild,q->data);
		}
		else
		{
			q=findMin(p->rightChild);
			p->data=q->data;
			p->rightChild=deleteNode(p->rightChild,q->data);
		}



	}

	else if(p->data>data)
	{
		p->leftChild=deleteNode(p->leftChild,data);
	}
	

	else
	{
		p->rightChild=deleteNode(p->rightChild,data);
	}

	
	p->height=getHeight(p);
	
	if(getBalance(p)==2 && getBalance(p->leftChild)==1 )
	{
		return LLRotate(p);
	}
	else if(getBalance(p)==2 && (getBalance(p->leftChild)==-1 || getBalance(p->leftChild)==0))
	{
		
		return LRRotate(p);
	}
	else if(getBalance(p)==-2 && getBalance(p->rightChild)==-1)
	{
		
		return RRRotate(p);
	}
	else if(getBalance(p)==-2 && getBalance(p->rightChild)==1)
	{
		return RLRotate(p);
	}




	return p;


}

struct AvlNode *findMax(struct AvlNode* p)
{
	
	while(p->rightChild)
	{
		p=p->rightChild;
	}

	return p;

}




struct AvlNode *findMin(struct AvlNode* p)
{

	
	while(p->leftChild)
	{
		p=p->leftChild;
	}

	return p;

}
void printPostOrder(struct AvlNode *p)
{
	if(!p)
	{
		return;
	}

	printPostOrder(p->leftChild);
	printPostOrder(p->rightChild);
	printf("%d ",p->data);
}

void printPreOrder(struct AvlNode *p)
{
	if(!p)
	{
		return;
	}

	printf("%d ",p->data);
	printPreOrder(p->leftChild);
	printPreOrder(p->rightChild);
}

void printInOrder(struct AvlNode *p)
{
	if(!p)
	{
		return;
	}

	printInOrder(p->leftChild);
	printf("%d ",p->data);
	printInOrder(p->rightChild);
}
int treeHeight(struct AvlNode *p)
{
	if(p==NULL)return 0;

	int heightOfLeft = treeHeight(p->leftChild);
	int heightOfRight = treeHeight(p->rightChild);

	return heightOfLeft > heightOfRight ? heightOfLeft+1 : heightOfRight+1;
}

