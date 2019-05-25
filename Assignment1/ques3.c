#include<stdio.h>

int stack[100];
 
void push(int);
int  top();
int  pop();
static int lid=-1;
int point();

void push(int key)
{
 if(lid==-1)	
 {
  stack[0]=key;
  lid=0;
 }
 else
 {   lid++;
     stack[lid]=key;
 }
} 

int top()
{ 
   if(lid>-1)
   {
	 //printf("%c ",stack[lid]);
     return stack[lid];
   }	 
   else 
	  // printf("Stack Empty\n");
   return 0;
   
} 
 
int pop()
{
 if(lid>-1)
 {  
    //printf("%c ",stack[lid]);
    lid--;
    return stack[lid+1];
    
 }	
   else 
	  // printf("Stack Empty\n");	
   return 0;
  
}  

int point()
{
	return lid;
}	


//stock span problem

void stockspan(int price[],int n, int span[])
{
  
 push(0);
 span[0]=1;
  for (int i = 1; i < n; i++)
   {
      
      while ( lid!=-1 && price[top()] <= price[i])
         pop();
      
	  if(lid==-1)   
	   span[i]=(i + 1);
       else
		    span[i]=(i - top());
      
	  push(i);
   }
   
   for(int i=0;i<n;i++)
	   printf("%d ",span[i]);
   printf("\n");
}

void main() 
{ 
    int n;
	printf("Enter number of days\n");
	scanf("%d",&n);

	int price[n];
    int span[n];
	
	printf("Enter stock prices for the %d days\n",n);
	for(int i=0;i<n;i++)
	   scanf("%d",&price[i]);
	stockspan(price,n,span);
}