#include<stdio.h>
#include<string.h>
#include<math.h>
static int precheck=0;
int posteval(char[],int);
int welcome();
void balance(char [],int);
void INtoPOST(char [],int);

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


int precedence(char c)
{
	
		
	if(c=='^')
		return 8;
	if(c=='/')
		return 7;
	if(c=='*')
		return 7;
	if(c=='+')
		return 5;
	if(c=='-')
		return 5;
	return -1;
}	

void operator(char c)
{   
    int a=pop();
    int b=pop();
	
	if(c=='+')
	 push(b+a);
  
    if(c=='-')
	 push(b-a);
    
    if(c=='*')
	 push(b*a);	
		
	if(c=='/')
	 push(b/a);
    
	if(c=='^')
	 push((int)pow(b,a)); 
}

void integer(char c)
{
 if(c=='0')
  push(0);	
 if(c=='1')
  push(1);	
 if(c=='2')
  push(2);	
 if(c=='3')
  push(3);	
 if(c=='4')
  push(4);	 
 if(c=='5')
  push(5);	
 if(c=='6')
  push(6);	
 if(c=='7')
  push(7);	
 if(c=='8')
  push(8);
 if(c=='9')
  push(9);		

}	

void main()
{  
 
 printf("Welcome");
 int i=0;      
	   do
	    {
		  i=welcome();
	    }while(i!=5); 
	   
}          
int welcome()
{
    
	
     int i;
	 printf("\n1 Matched Brackets\n2 Infix to postfix\n3 Postfix evaluation\n4 Infix to prefix\n5 Exit\n");
	 scanf("%d",&i);
    	switch(i)
		{
		 case 1: printf("Enter String\n");
	             char str1[50];
	             scanf("%s",str1);
				 int n1 = strlen(str1);
	             balance(str1,n1);
				 lid=-1;
				 return 0;
	     
		 case 2: printf("Enter String\n");
	             char str2[50];
	             scanf("%s",str2);
    
	             int n2 = strlen(str2);
	             INtoPOST(str2,n2);
		         lid=-1;
           		 return 0;
		 
		 case 3: printf("Enter String\n");
                 char str3[50];
                 scanf("%s",str3);
    
                 int n3 = strlen(str3);
	
                 printf("%d\n",posteval(str3,n3));
		         lid=-1;
				 return 0;
				 
		 case 4: printf("Enter String\n");
                 char str4[50];
                 scanf("%s",str4);
    
                 int n4 = strlen(str4);
	             
                 precheck=1;
				 for(int i=0;i<n4;i++)
					 if(str4[i]==')')
						 str4[i]='(';
					 else 
						 if(str4[i]=='(')
						 str4[i]=')';
				 INtoPOST(strrev(str4),n4);
		         precheck=0;
  				 lid=-1;
				 return 0;
             
		
		 case 5:  lid=-1;
		          return 5;
		}		 
}					 
int posteval(char str[],int n)
{
 for(int i=0;i<n;i++) 
 {
	if(str[i]=='^'||str[i]=='/'||str[i]=='*'||str[i]=='+'||str[i]=='-')
     	operator(str[i]);
    else if(str[i]>='0' && str[i]<='9')
		integer(str[i]);	
 }
 return pop();

	
}					 
				 
 void balance(char str[50],int n)
{
	
if(str[0]==']' || str[0]=='}' || str[0]==')')	
	   { printf("Not Balanced\n");
   return;}
 if(str[0]=='[' || str[0]=='{' || str[0]=='(')
 push(str[0]);
 for(int i=1;i<n;i++)
 {
  if(lid==-1)
   if(str[i]==']' || str[i]=='}' || str[i]==')')
   { printf("Not Balanced\n");
   return;}
 if(top()!=0)
	{
	 if(top()=='[')
		 {
		 if(str[i]==']')
	      pop();
	     }

	// else if(str[i]=='{' || str[i]=='(')
		// push(str[i]);

    else if(top()=='{')
        {
		 if(str[i]=='}')
	      pop();
	     }
    // else if(str[i]=='(')
		// push(str[i]);

	else if(top()=='(')
		{
		 if(str[i]==')')
	      pop();
	     }
 
  }
  if(str[i]=='[' || str[i]=='{' || str[i]=='(')
	  push(str[i]);
  }
  
  if(lid>-1)
	  printf("Not Balanced\n");
  else printf("Balanced\n");

  

 }

 void INtoPOST(char str[],int n)
{
 char postfix[n];
 int k=0;
  
	 

	for(int i=0;i<n;i++)
	{ 
	     if((str[i]<='Z' && str[i]>='A')||(str[i]<='z' && str[i]>='a'))
		   postfix[k++]=str[i];
	     
         else if(str[i]=='(')
			push(str[i]); 


         else if(str[i]==')')
		 {
			 while(lid!=-1 && top()!='(')
			 if(top()!='('||top()!=')')
				    postfix[k++]=pop();
			 if(lid!=-1 && top()!='(')	
		       return;	//invalid expression
		     else pop();	
		 }
		else if(str[i]=='^'||str[i]=='/'||str[i]=='*'||str[i]=='+'||str[i]=='-')
		
		   {
			
		  
				while(lid!=-1 && precedence(str[i])<=precedence(top()))
				{
					if(top()!='('||top()!=')')
				    postfix[k++]=pop();
				}
			push(str[i]);
			
		    }	 
	} 
	while(lid!=-1)
				{
					if(top()!='('||top()!=')')
				    postfix[k++]=pop();
				}
	
	

	
     

    postfix[k++]='\0';	 
	if(precheck==0)
		printf("%s",postfix);	
    else if(precheck==1)
	{	
      
	  printf("%s",strrev(postfix));
	}
}


		 
				 
				 