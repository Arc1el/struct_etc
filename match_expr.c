#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 100


typedef char element;

typedef struct stack{
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

int check_matching(char *in)
{
	stack s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(&s);

	for (i = 0; i < n; i++)
	{
		ch = in[i];
		switch (ch) {
		case '(':
		case '[':
		case '{':
			push(&s, ch);
			break;
		case ')':
		case ']':
		case '}':
			if (is_empty(&s)) return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
					return 0;
			}
			break;
		}
	}
	if (!is_empty(&s)) return 0;
	return 1;
}

int main()
{
	char *p = "{A[(i+1)]=0}";

	if (check_matching(p) == 1)
		printf("성공");
	else
		printf("실패");
	
	return 0;
}
