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
//printf("%c ",stack[lid]);
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