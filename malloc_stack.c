#define _CRT_NO_WARNINGS_
#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct elemnt{
	int student_no;
	char name[MAX_STRING];
}element;

typedef struct stack {
	int stack_top;
	int stack_cap;
	element *stack;
}stack;

void init_stack(stack*);
int is_full(stack*);
int is_empty(stack*);
void push(stack*, element);
element pop(stack*);
element peek(stack*);
void free_stack(stack*);

int main(void)
{
	element s1 = { 20163309, "Kim" };

	element pop1;

	stack st;

	init_stack(&st);
	push(&st, s1);
	pop1 = pop(&st);

	printf("%d\n", pop1.student_no);


}

void init_stack(stack *s)
{
	s->stack = (element *)malloc(s->stack_cap * sizeof(element));
	s->stack_top = -1;
	s->stack_cap = 1;
}

void free_stack(stack *s)
{
	free(s);
}


int is_full(stack *s) {
	return (s->stack_top == MAX_STACK_SIZE - 1);
}

int is_empty(stack *s) {
	return (s->stack_top == -1);
}

element pop(stack *s)
{
	if (!is_empty(s))
	{
		element temp = s->stack[s->stack_top];
		s->stack_top--;
		return temp;
	}
	else
		fprintf(stderr, "stack is empty"); exit(1);
	
}

void push(stack *s, element item) {
	if (!is_full(s))
	{
		s->stack_top++;
		s->stack[s->stack_top] = item;
	}
	else
		fprintf(stderr, "stack is full");
}

element peek(stack *s)
{
	if (!is_empty(s))
	{
		return s->stack[s->stack_top];
	}
	else
		fprintf(stderr, "stack is empty"); exit(1);
}
