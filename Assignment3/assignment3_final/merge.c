#include<stdlib.h>
#include<stdio.h>
void swap(int* a,int* b)
{
  int t=*a;
  *a=*b;
  *b=t;
}

void quicksort(int arr[],int start,int end)
{
 int pivot=arr[end];
 int i=start;
 int j=start+1;
 
 while(j<end)
 {
	if(arr[j]<=pivot)
	{
		i++;
		swap(&arr[i],&arr[j++]);
	}
	else j++;
 }
 
 swap(&arr[i+1],&arr[end]);
 quicksort(arr,start,i-1);
 quicksort(arr,i+1,end);
}

void printarray(int arr[],int size)
{
	//printf("\n");
	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void main()
{
	int a[]={8,0,7,-1};
	quicksort(a,0,4);
	printarray(a,4);
}