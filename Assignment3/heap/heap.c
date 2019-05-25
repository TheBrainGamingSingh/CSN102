#include<stdio.h>
#include<stdlib.h>

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

 heap edgelist;
 heap build;
 heap* bldhp=&build;
 heap* minedge=&edgelist;
 void insert(heap* root,int key)
 {
	root->array[root->count]=key;
	root->count+=1;
	int p,c;
	c=root->count-1;
	int temp;
	while(c>=0)
	{
		if(c%2)
			p=(c-1)/2;
		else 
			p=(c-2)/2;
		if(root->array[c]<root->array[p])
		{
			temp=root->array[c];
			root->array[c]=root->array[p];
			root->array[p]=temp;
		}
		c=p;
	}

 }
 
 void print(heap* list)
 {
	 int sum=1,j=1;
	for(int i=0;i<list->count;i++) 
	{
		printf("%4d ",list->array[i]);
		if((i+1)%sum==0)
		{
			printf("\n");
		    j*=2;
			sum+=j;
		}	
	}
 }
 
 void heapify(heap* root,int index)
 {
	while(root->array[index]!=0)
	{
		int temp;
		//printf("check");
		
		 if(root->array[index]>root->array[left(index)] && root->array[index]>root->array[right(index)] && root->array[right(index)]!=0)
		{
			
			if(root->array[left(index)]==min(root->array[left(index)],root->array[right(index)]))
			{
				
				temp=root->array[left(index)];
				root->array[left(index)]=root->array[index];
				root->array[index]=temp;
				index=left(index);
				
			}
			else 
			{
				temp=root->array[right(index)];
				root->array[right(index)]=root->array[index];
				root->array[index]=temp;
				index=right(index);
			}
		}
		
		else if(root->array[index]>root->array[left(index)] && root->array[left(index)]!=0)
			{
				
				temp=root->array[left(index)];
				root->array[left(index)]=root->array[index];
				root->array[index]=temp;
				index=left(index);
				
			}
		else if(root->array[index]>root->array[right(index)] && root->array[right(index)]!=0)
			{
				temp=root->array[right(index)];
				root->array[right(index)]=root->array[index];
				root->array[index]=temp;
				index=right(index);
			}
			
		else break;	
	}		
 }
 
 int deletemin(heap* root)
 {
	 int del=root->array[0];
	 root->count-=1;
	 root->array[0]=root->array[root->count];
	 root->array[root->count]=0;
	 heapify(root,0);
	 return del;
 }
 
 void buildheap(heap* root)
 {
	 int k=((root->count)/2)-1;
	 for(int m=k;m>=0;m--)
		 heapify(root,m);
 }
void main()
{
/* edgelist.count=0;
 insert(minedge,75);	
 insert(minedge,15);	
 insert(minedge,45);
 insert(minedge,35);	
 insert(minedge,25);	
 insert(minedge,5);	
 insert(minedge,65);
 print(minedge);
 printf("\n\n");
 deletemin(minedge);
 printf("\n\n");
 print(minedge);
 insert(minedge,13);
 printf("\n\n");
 print(minedge); 
 insert(minedge,43);
 insert(minedge,34);	
 deletemin(minedge);
 
 printf("\n\n");
 print(minedge);
 
 insert(minedge,21);	
 insert(minedge,7);
 printf("\n\n");
 print(minedge);*/
 

 build.count=0;
 build.array[build.count++]=10;
 build.array[build.count++]=7;
 build.array[build.count++]=4;
 build.array[build.count++]=8;
 build.array[build.count++]=5;
 build.array[build.count++]=3;
 build.array[build.count++]=1;
 build.array[build.count++]=2;
 build.array[build.count++]=9;
 build.array[build.count++]=6;
 buildheap(bldhp);
 printf("\n\n");
 print(bldhp);
} 