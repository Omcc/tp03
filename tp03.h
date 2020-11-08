#include <stdio.h>

#ifndef TP03
#define TP03

struct AvlNode{
	int data;
	struct AvlNode* leftChild;
	struct AvlNode* rightChild;
	int height;
};



int getHeight(struct AvlNode *p);
struct AvlNode* insertAvl(struct AvlNode *head,int data);

