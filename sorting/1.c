#include<stdio.h>

void swap(int* a,int* b)
{
  int t=*a;
  *a=*b;
  *b=t;
}

int mergesort();

void merge(int a1[],int start,int mid,int end)
{

  int i=start,j=mid,k=start;
  int a2[end];
  for(int m=start;m<end;m++)
	{
		a2[m]=a1[m];
		//printf("%d ",a2[m] );
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
  if(i<mid)
  {
    for(int i1=i;i1<mid;i1++)
     a1[k++]=a2[i1];
  }
  else if(j<end)
  {
     for(int i1=j;i1<end;i1++)
      a1[k++]=a2[i1];
  }
}
void main()
{
  int x=5,y=3;
  printf("%d %d\n",x,y);
  swap(&x,&y);
  printf("%d %d\n",x,y);

  int arr3[]={2,4,7,9,1,3,8,10};
  merge(arr3,0,4,8);
for(int i=0;i<8;i++)
  printf("%d ",arr3[i] );
}
