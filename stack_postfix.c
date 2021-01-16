#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct stack {
	element *data;
	int stack_top;
	int stack_cap;
}stack;

void init_stack(stack* s) {
	s->stack_top = -1;
	s->stack_cap = 1;
	s->data = (element *)malloc(s->stack_cap * sizeof(element));
}

int is_empty(stack* s)
{
	return (s->stack_top == -1);
}

int is_full(stack* s)
{
	return (s->stack_top == (MAX_STACK_SIZE - 1));
}

void push(stack *s, element item)
{
	if (is_full(s))
	{
		s->stack_cap *= 2;
		s->data = (element *)realloc(s->data, s->stack_cap * sizeof(element));
	}
	s->stack_top++;
	s->data[s->stack_top] = item;
}

element pop(stack *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "stack is empty");
		exit(1);
	}
	else
	{
		element temp = s->data[s->stack_top];
		s->stack_top--;
		return temp;
	}
}

int eval(char *in)
{
	int op1, op2, i = 0;
	int len = strlen(in);

	char ch;
	stack s;

	init_stack(&s);

	for (i = 0; i < len; i++)
	{
		ch = in[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
			push(&s, ch - '0');
		else
		{
			op2 = pop(&s);
			op1 = pop(&s);

			switch (ch) {
			case '+':
				push(&s, op1 + op2); break;
			case '-':
				push(&s, op1 - op2); break;
			case '*':
				push(&s, op1 * op2); break;
			case '/':
				push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

int main()
{
	printf("후위표기식 82/3-32*+\n");
	printf("결과값은 %d\n", eval("82/3-32*+"));
	return 0;
}
