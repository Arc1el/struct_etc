#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct circleq {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}cirq;

void init_q(cirq *q)
{
	q->front = q->rear = 0;
}

int is_empty(cirq *q)
{
	return (q->front == q->rear);
}

int is_full(cirq *q)
{
	return ((q->front)%MAX_QUEUE_SIZE == (q->rear+1)/MAX_QUEUE_SIZE);
}

void q_print(cirq *q)
{
	int i;
	printf("front : %d , rear : %d   ", q->front, q->rear);
	if (!is_empty(q))
	{
		i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void en_q(cirq *q, element item)
{
	if (is_full(q))
	{
		fprintf(stderr, "queue is full");
		return;
	}
	else
	{
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

element de_q(cirq *q)
{
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
