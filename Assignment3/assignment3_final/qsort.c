#include<stdlib.h>
#include<stdio.h>
static int count=0;
void swap(int* a,int* b)
{
  int t=*a;
  *a=*b;
  *b=t;
}

int partition(int arr[],int start,int end)
{
	int pivot=arr[start];
	int i=start-1;
	int j=end+1;
	while(1)
	{
		do
		{
			i++;
			count++;
		}while(arr[i]<pivot);
		
		do
		{
			j--;
			count++;
		}while(arr[j]>pivot);
		
		if(i>=j)
			return j;
		
		swap(&arr[i],&arr[j]);
		
	}
}

void quicksort(int arr[],int start,int end)
{
	if(start<end)
	{
		int mid=partition(arr,start,end);
		quicksort(arr,start,mid);
		quicksort(arr,mid+1,end);
	}
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
	int a[]={0,7,4,2,1,5,9,8,3,6};
	quicksort(a,0,9);
	printarray(a,10);
	
	printf("Number of comparisions: %d\n",count);
	int b[]={0,1,2,3,4,5,6,7,8,9};
	count=0;
	quicksort(b,0,9);
	printarray(b,10);
	printf("Number of comparisions: %d\n",count);
}