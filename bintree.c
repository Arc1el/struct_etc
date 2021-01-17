#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
	int data;
	struct tree *left, *right;
}tree;

/*
     n1
   /  |
  n2  n3   */

int main()
{
	tree *node1, *node2, *node3;
	node1 = (tree *)malloc(sizeof(tree));
	node2 = (tree *)malloc(sizeof(tree));
	node3 = (tree *)malloc(sizeof(tree));

	node1->data = 10;
	node2->data = 20;
	node3->data = 30;

	node1->left = node2;
	node1->right = node3;

	node2->left = NULL;
	node2->right = NULL;

	node3->left = NULL;
	node3->right = NULL;

	free(node1);
	free(node2);
	free(node3);
}
