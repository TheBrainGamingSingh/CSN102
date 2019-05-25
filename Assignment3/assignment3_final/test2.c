#include<stdio.h>
#include<string.h>

void merge(int arr[],int start,int mid,int end)
{
 int i,j,k;
 int n1=mid+1-start;
 int n2=end-mid;
 k=start;
 
 int larr[n1];
 int rarr[n2];
 
 for(i=0;i<n1;i++)
	larr[i]=arr[start+i];
	
 for(j=0;j<n1;j++)
	rarr[j]=arr[mid+1+j];

	i=0;j=0;
	
	while(i<n1 && j<n2)
	{
		if(larr[i]<rarr[j])
			arr[k++]=larr[i++];
		else 
			arr[k++]=rarr[j++];
	}
	
	while(i<n1)
		arr[k++]=larr[i++];
	while(j<n2)
		arr[k++]=rarr[j++];
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
	int a[]={8,4};
	merge(a,0,1,2);
	printarray(a,2);
}