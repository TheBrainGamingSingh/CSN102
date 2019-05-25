#include<stdio.h>
#include<string.h>
void swap(int* a,int* b)
{
  int t=*a;
  *a=*b;
  *b=t;
}

void merge(int a1[],int start,int mid,int end)
{
  printf("\n\n");
  int i=start,j=mid,k=start;
  int a2[end];
  printf("%d %d %d\n",i,j,k);
  for(int m=start;m<end;m++)
	{
		a2[m]=a1[m];
		printf("%d ",a2[m] );
	}	
  while(i<mid && j<end)
  {
    if(a2[i]<a2[j])
    {
      a1[k++]=a2[i++];
    }
    else
      a1[k++]=a2[j++];
  }
    while(i<mid)
     a1[k++]=a2[i++];
 
     while(j<end)
      a1[k++]=a2[j++];
   
   printf("\n");
  for(int m=start;m<end;m++)
	{
		//a2[m]=a1[m];
		printf("%d ",a1[m] );
	}
  
}


void mergesort(int arr[],int start,int end)
{
	if(start==end)
		return;
	else 
	{
		int mid=(start+end)/2;
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);	
		merge(arr,start,mid,end);
	}
}

void main()
{
	/*int array[10]={8,4,6,9,5,1,3,7,2,10};
	mergesort(array,0,10);
	
	for(int i=0;i<10;i++)
		printf("%d ",array[i] );*/
	
	int array2[8]={8,7,6,5,4,3,2,1};
	mergesort(array2,0,8);
	printf("\n\n");
	for(int i=0;i<8;i++)
		printf("%d ",array2[i] );
}