#include<stdlib.h>
#include<stdio.h>
 static int count=0;
 
void merge(int arr[], int start, int mid, int end)
{
    int i, j, k;
	k=start;
    int n1=(mid+1)-start;
    int n2=end-mid;
    int larr[n1], rarr[n2];
 
    for(i=0;i<n1;i++)
        larr[i]=arr[start+i];
    for(j=0;j<n2;j++)
        rarr[j]=arr[mid+1+j];
    i=0;j=0; 
   
    while (i<n1 && j<n2)
    {
        count++;
		if (larr[i]<=rarr[j])
            arr[k++]=larr[i++];
        else
            arr[k++]=rarr[j++];
    }
	
    while(i<n1)
     arr[k++]=larr[i++];
 
    while(j<n2)
        arr[k++]=rarr[j++];

}
 
void mergesort(int arr[], int start, int end)
{
    if(start<end)
    {
        int mid=(end+start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
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
	int a[]={9,8,7,6,5,4,3,2,1,0};
	mergesort(a,0,9);
	printarray(a,10);
	
	printf("Number of comparisions: %d\n",count);
	int b[]={0,1,2,3,4,5,6,7,8,9};
	count=0;
	mergesort(b,0,9);
	printarray(b,10);
	printf("Number of comparisions: %d\n",count);
}