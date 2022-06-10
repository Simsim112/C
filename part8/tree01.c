#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
	char ch;
	struct tnode* left;
	struct tnode* right;
}TNode;

TNode* createNode(char ach) 
{
	TNode* newNode = (TNode*)malloc(sizeof(TNode));
	if (newNode == NULL) return;

	newNode->ch = ach;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
};

void makeTreeNode(TNode* aroot, TNode* al, TNode* ar)
{
	aroot->left = al;
	aroot->right = ar;
}

int main() 
{
	TNode* t1 = createNode('a');
	TNode* t2 = createNode('b');
	TNode* t3 = createNode('c');
	TNode* t4 = createNode('d');
	TNode* t5 = createNode('e');
	TNode* t6 = createNode('f');
	TNode* t7 = createNode('g');
	TNode* t8 = createNode('h');
	TNode* t9 = createNode('i');

	printf("%c %c %c\n", t1->ch, t2->ch, t3->ch);
	makeTreeNode(t1, t2, t3);
	makeTreeNode(t2, t4, t5);
	makeTreeNode(t3, t6, t7);
	makeTreeNode(t4, t8, NULL);
	makeTreeNode(t4, NULL, t9);

	printf("%c %c %c", t1->ch, t1->left->ch, t1->right->ch);
	return 0;
}