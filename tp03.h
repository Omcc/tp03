#include <stdio.h>

#ifndef TP03
#define TP03

struct AvlNode{
	int data;
	struct AvlNode* leftChild;
	struct AvlNode* rightChild;
	int height;
}*root;



int getHeight(struct AvlNode *p);
struct AvlNode* insertAvl(struct AvlNode *p,int data);
struct AvlNode* LLRotate(struct AvlNode *p);
struct AvlNode* LRRotate(struct AvlNode *p);
struct AvlNode* RRRotate(struct AvlNode *p);
struct AvlNode* RLRotate(struct AvlNode *p);
struct AvlNode* deleteNode(struct AvlNode *p,int data);

struct AvlNode* findMax(struct AvlNode *p);
struct AvlNode* findMin(struct AvlNode *q);
void printPost(struct AvlNode *head);

#endif
