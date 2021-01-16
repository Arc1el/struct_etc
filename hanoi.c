#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ARRSIZE 10

typedef struct stuName {
	char name[10];
	int age;
	double gpa;
}student;

typedef struct section {
	int x;
	int y;
}*psec;

int facto(int n);
int sub(int n);

double slow_power(double x, int n)
{
	int i = 0;
	double result = 1;
	for (i = 0; i < n; i++)
	{
		result *= x;
	}
	return result;
}
double fast_power(double x, int n)
{
	if (n == 0) return 1;
	else if ((n % 2) == 0)
	{
		return fast_power(x*x, n / 2);
	}
	else
	{
		return x * fast_power(x*x, (n - 1) / 2);
	}
}
int fib(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	int i;

	int pp = 0;
	int p = 1;
	int result = 0;
	for (i = 2; i <= n; i++)
	{
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}

void hanoi(int n, char from, char temp, char to)
{
	if (n == 1) printf("1개를 %c에서 %c로 옮긴다\n", from, to);
	else {
		hanoi(n - 1, from, to, temp);
		printf("%d개를 %c 에서 %c로 보낸다\n", n, from, to);
		hanoi(n - 1, temp, from, to);
	}
}

void printarr(int arr[]) {
	int i = 0;
	for (i = 0; i < 10; i++) {
		printf("%d", arr[i]);
	}
}

void insert(int arr[], int loc, int value)
{
	int i;
	int items = 10;
	for (i = items-1; i < loc; i++)
	{

	}

}
int main()
{
	int dat = facto(5);
	int dat2 = sub(10);
	double dat3 = slow_power(2, 3);
	double dat4 = fast_power(2, 3);
	int dat5 = fib(4);
	printf("%d\n", dat);
	printf("%d\n", dat2);
	printf("%f\n", dat3);
	printf("%f\n", dat4);
	printf("%d\n", dat5);
	//hanoi(4, 'A', 'B', 'C');

	student s1;
	strcpy(s1.name, "kim");
	s1.age = 25;
	s1.gpa = 3.98;

	student s2 = { "lee", 23, 4.3 };

	psec ps1 = malloc(sizeof(psec));
	ps1->x = 1;
	ps1->y = 2;

	void *ptr;

	ptr = ps1;

	printf("x : %d\n", ((psec)ptr)->x);
	printf("y : %d\n", ((psec)ptr)->y);

	int two[10] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
	printarr(two);

	//free(ps1);
	return 0;

}


int facto(n)
{
	int dat = 1;
	int i;
	for (i = 1; i <= n; i++)
	{
		dat *= i;
	}
	return dat;
}

int sub(n)
{
	int i, result;
	result = 0;
	for (i = n; i > 0; i = i - 3)
	{
		result = result + i;
	}
	return result;
}
