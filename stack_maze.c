#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct stack {
	element data[MAX_STACK_SIZE];
	int top;
}stack;

typedef struct element{
	short r;
	short c;
}element;

void init_stack(stack *s)
{
	s->top = -1;
}

int is_empty(stack *s)
{
	return (s->top == -1);
}

int is_full(stack *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(stack *s, element item)
{
	if (is_full(s))
	{
		fprinf(stderr, " stack is full");
		return;
	}
	else {
		s->top++;
		s->data[s->top] = item;
	}
}

element pop(stack *s)
{
	if (is_empty(s))
	{
		fprinf(stderr, " stack is empty");
		return;
	}
	else
	{
		element temp = s->data[s->top];
		s->top--;
		return temp;
	}
}

element here = { 0, 1 };
element entry = { 0, 1 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};

void push_loc(stack *s, int r, int c)
{
	if (maze[r][c] != '1' && maze[r][c] != '.')
	{
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++)
	{
		for (int c = 0; c < MAZE_SIZE; c++)
		{
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main()
{
	int r, c;
	stack s;
	init_stack(&s);
	here = entry;

	while (maze[here.r][here.c] != 'x')
	{
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);

		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c -1);
		push_loc(&s, r, c +1);
		if (is_empty(&s))
		{
			fprintf(stderr, "실패");
			return;
		}
		else
			here = pop(&s);
	}
	printf("성공");
	return 0;
}
