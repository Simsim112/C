#include <stdio.h>
#include <stdlib.h>

typedef struct Tnode {
	char ch;
	struct Tnode* right;
	struct Tnode* left;
}TNode;

TNode* createNode(char ach)
{
	TNode* newNode = (TNode*)malloc(sizeof(TNode));
	if (newNode == NULL) return;

	newNode->ch = ach;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void makeTreeNode(TNode* aroot, TNode* al, TNode* ar)
{
	aroot->left = al;
	aroot->right = ar;
}

void preorderTree(TNode* aroot)		//전위 순회
{
	if (aroot == NULL) return;

	printf("%c ", aroot->ch);
	preorderTree(aroot->left);
	preorderTree(aroot->right);

}

void inorderTree(TNode* aroot)		//중위 순회
{
	if (aroot == NULL) return;

	inorderTree(aroot->left);
	printf("%c ", aroot->ch);
	inorderTree(aroot->right);
}

void postorderTree(TNode* aroot)
{
	if (aroot == NULL) return;

	postorderTree(aroot->left);
	postorderTree(aroot->right);
	printf("%c ", aroot->ch);
}

int main()
{
	TNode* t1 = createNode('1');
	TNode* t2 = createNode('2');
	TNode* t3 = createNode('3');
	TNode* t4 = createNode('4');
	TNode* t5 = createNode('5');
	TNode* t6 = createNode('6');
	TNode* t7 = createNode('7');
	TNode* t8 = createNode('8');
	TNode* t9 = createNode('9');
	makeTreeNode(t1, t2, t3);
	makeTreeNode(t2, t4, t5);
	makeTreeNode(t3, t6, t7);
	makeTreeNode(t4, t8, NULL);
	makeTreeNode(t5, NULL, t9);
	//preorderTree(t1);
	//inorderTree(t1);
	postorderTree(t1);

	//printf("%c %c %c", t1->ch, t1->left->ch, t1->right->ch);
	return 0;
}