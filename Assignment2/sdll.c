//sorted dll
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list
{
 char data[20];
 
 struct list* next;
 struct list* prev;
 
} list; 

list* headA=NULL;
//list* tailA=NULL;
list* headB=NULL;
//list* tailB=NULL;
list* newnode(char[],list*,list*);
 
 list** sidecheck()	
 {	int side;
	 
	  printf("Which side? A(Press 1)/B(Press 2)\n");
		 scanf("%d",&side);
	    if(side==1)
	     return &headA;
	
	    else if(side==2)
	     return &headB;
		else 
	 {
	   printf("Enter valid side"); 
	   sidecheck();
	 }
 
 }					  
 void printlist(list* start)
 { 
    if(start==NULL)
		return;
	 list* temp=start;
	 while(temp!=NULL)
	 {
		printf("%s ",temp->data);
	    temp=temp->next;
		
	 }
	 printf("\n");
 }

 list* newnode(char ndata[20],list* nnext,list* nprev)
 {
	 list* newn = (list*)malloc(sizeof(list));
	 strcpy(newn->data,ndata);
	 newn->next=nnext;
	 newn->prev=nprev;
	 
	 return newn;
 }

 list* insertfront(list* start,char ndata[20])
 { 
	return newnode(ndata,start,NULL); 
 }

 
/*  
void updatetail(list** head,list** tail)
{
	if(*head->next==NULL || *head==NULL)
		*tail=*head;
	return;
}
void updatehead(list** head,list** tail)
{
	if(*tail->prev==NULL || *tail==NULL)
		*head=*tail;
	return;
}
*/   


void insert(char data[20],list** start) 
{
	//list empty
	if(*start==NULL)
		*start=newnode(data,NULL,NULL);
	
	  else if (strcmp((*start)->data,data)>0) 
	  {
        *start=insertfront(*start,data);
	  }
     else
	 {
        list* temp = *start;
        
        //searching the node
      while(temp->next!= NULL)
		  if(strcmp(temp->next->data,data)>0)
           break;
 	     else temp=temp->next;
        
		
		list* new=newnode(data,temp->next,temp);
        
		if (temp->next!=NULL)
            new->next->prev = new;
 
         temp->next=new;
    
    }
} 


void main()
{
	ListOP:
	          printf("\nOperations available\n1 Insert\n5 Print\n7 Exit\n");
	          int w;
	          scanf("%d",&w);
			  list** head;
	          switch(w)
			  {
				  case 1: 
						{
							
						 printf("Enter data\n");
	                      int side; char key[20];
						  scanf("%s",&key);
						  head=sidecheck(); 
						 
						  insert(key,head);
						 
     					  printf("List:");
						  printlist(*head);

						  goto ListOP;
						}
				 case 5: 
						{
         			     head=sidecheck(); 
				         if(*head!=NULL)
				           {  
 					           printf("List:");
			                   printlist(*head);	
			               }
						   else printf("List empty\n");
						 
 						  goto ListOP;
						} 
				  case 7: return ;
	          } 
}