#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct listnode {
	element data;
	struct listnode *link;
}listnode;

listnode* insert_first(listnode *head, element value)
{
	listnode *node2 = (listnode *)malloc(sizeof(listnode));
	node2->data = 30;
	node2->link = head;
	head = node2;
	return head;
}

listnode* insert(listnode *head, listnode *pre, element value)
{
	listnode *node3 = (listnode *)malloc(sizeof(listnode));
	node3->data = value;
	node3->link = pre->link;
	pre->link = node3;
	
	return head;
}

listnode* delfirst(listnode *head)
{
	listnode *removed;

	if (head == NULL) return NULL;

	removed = head;
	head = removed->link;
	free(removed);

	return head;

}

listnode* deletelist(listnode *head, listnode * pre)
{
	listnode *removed;
	removed = pre->link;
	pre->link = removed->link;

	free(removed);
	return head;
}

void print_list(listnode *head)
{
	listnode *p;
	for (p = head; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL\n");
}


int main()
{
	listnode *head = NULL;

	int i;
	for (i = 0; i < 5; i++)
	{
		head = insert_first(head, i);
		print_list(head);
	}
	for (i = 0; i < 5; i++)
	{ 
		head = delfirst(head);
		print_list(head);
	}
}
