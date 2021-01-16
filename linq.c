#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct linq {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}queue;

void init_q(queue *q)
{
	q->front = -1;
	q->rear = -1;
}

void q_print(queue *q)
{
	int i;
	for (i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (i <= q->front || i > q->rear)
			printf("|");
		else
			printf("%d|", q->data[i]);
	}
	printf("\n");
}

int is_full(queue *q)
{
	return (q->rear == MAX_QUEUE_SIZE - 1);
}

int is_empty(queue *q)
{
	return (q->front == q->rear);
}

void enqueue(queue *q, element item)
{
	if (is_full(q))
	{
		fprintf(stderr, "q is full \n");
	}
	else
	{
		q->rear++;
		q->data[q->rear] = item;
	}
}

element dequeue(queue *q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "q is empty");
	}
	else 
	{
		q->front++;
		element item = q->data[q->front];
		return item;
	}
}

int main()
{
	element item = 0;
	queue q;
	init_q(&q);

	enqueue(&q, 10); q_print(&q);
	enqueue(&q, 20); q_print(&q);
	enqueue(&q, 30); q_print(&q);

	item = dequeue(&q); q_print(&q);
	item = dequeue(&q); q_print(&q);
	item = dequeue(&q); q_print(&q);

	return 0;
}
