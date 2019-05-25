#include<stdio.h>
#include<stdlib.h>

//newheap
int left(int i)
{
	return 2*i + 1;
}
int right(int i)
{
	return 2*i + 2;
}

int min(int a,int b)
{
	return a<b ? a : b;
}

 typedef struct heap{
	 
	 int array[256];
	 int count;
 } heap;