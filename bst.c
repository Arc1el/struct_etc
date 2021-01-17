#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct tree {
	struct tree *left;
	struct tree *right;
	element data;
	int key;
}tree;

tree* search(tree *t, int key)
{
	if (t == NULL)
		return NULL;
	if (key == t->key)
		return t;
	else if (key < t->key)
		search(t->left, key);
	else
		search(t->right, key);
}

tree* iter_search(tree *t, int key)
{
	while (t != NULL) {
		if (t == NULL)
			return NULL;
		if (key == t->key)
			return t;
		else if (key < t->key)
			t = t->left;
		else
			t = t->right;
	}
	return NULL;
}

tree* newnode(int key)
{
	tree *newnode;
	newnode = (tree *)malloc(sizeof(tree));
	newnode->key = key;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

tree* insert(tree *t, int key)
{
	if (t == NULL)
		t = newnode(key);
	if (t->key > key)
		t->left = insert(t->left, key);
	else if (t->key < key)
		t->right = insert(t->right, key);
	return t;
}

tree* min_val_node(tree *t)
{
	tree *temp = t;
	while (temp != NULL)
	{
		temp = temp->left;
	}
	return temp;
}

tree* max_val_node(tree *t)
{
	tree *temp = t;
	while (t != NULL)
	{
		temp = temp->right;
	}
	return temp;
}

tree* del_node(tree *t, int key)
{
	tree *temp;
	if (t == NULL)
		return t;
	if (t->key < key)
		t->left = del_node(t->left, key);
	else if(t->key > key)
		t->right = del_node(t->right, key);
	else
	{
		if (t->left == NULL)
		{
			temp = t->right;
			free(t);
			return temp;
		}
		else if (t->right == NULL)
		{
			temp = t->left;
			free(t);
			return temp;
		}
		else if (t->left == NULL)
		{
			temp = t->right;
			free(t);
			return temp;
		}
		
		temp = min_val_node(t->right);
		t->key = temp->key;
		t->right = del_node(t->right, t->key);
	}
	return t;
}

void inorder(tree *t)
{
	if (t != NULL) {
		inorder(t->left);
		printf("[%d]", t->key);
		inorder(t->right);
	}
}
