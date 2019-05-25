#include<stdio.h>
#include<stdlib.h>
#define M 99999999

typedef struct list
{
 int data[4];

 struct list* next;
 //struct list* prev;
 
} list; 


list* head[10];
list **headptr=NULL;
list* newnode(list*);


 list* newnode(list* nnext)
 {
	 list* newn = (list*)malloc(sizeof(list));
	 newn->data[0]=M;
	 newn->data[1]=M;
	 newn->data[2]=M;
	 newn->data[3]=M;
	
	 newn->next=nnext;
	 
	 return newn;
 }
 
 
 void main()
 {    int i=0;
	  Operations:
	
      printf("Operations Available \n1 Enter data\n2 Print data\n3 Exit\n");	
      scanf("%d",&i);
   	  
	  switch(i){
	  
	  case 1: 
	          printf("Enter an integer\n");
	          int key=0;
              int j=0;
			  scanf("%d",&key);
			 if(key<0) 
			   j=((-1)*key)%10;
		     else 
				 j=key%10;
			
      			headptr=&head[j];
			    if(*headptr==NULL)
					  *headptr=newnode(NULL);
				  list* temp = *headptr;
				 
				while(temp->next!=NULL)
                     temp=temp->next;  					  
				   
				for(int index=0;index<4;index++)
				{
					if(temp->data[index]==M)
					{
						temp->data[index]=key;
						break;
					}
					else if(index==3 && temp->data[3]!=M)
					{
						temp->next=newnode(temp->next);
						temp->next->data[0]=key;
					}
				}	
				
				goto Operations;
						  
	 case 2:  printf("Enter a digit\n");
	          int key1=0;
              
			  scanf("%d",&key1);
			  
             	 headptr=&head[key1];
			
			  

              list* temp1= *headptr;
	          int count=0;
			  printf("Data: "); 
			  while(temp1!=NULL)
			  {
				
				  for(int x=0;x<4;x++)
				  {
					 if(temp1->data[x]!=M) 
       				  printf("%d ",temp1->data[x]);
				     else break;
				  }	
				 // printf("\n address is :%p",temp1);
                  count++;
                temp1=temp1->next;				  
		      }
			  printf("\nNumber of files: %d\n",count);
			  goto Operations;
	 case 3: return;
	 

	 }
	  
	 return;
 }