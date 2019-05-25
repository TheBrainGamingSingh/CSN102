#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list
{
 char data[50];
 struct list* next;
 //struct list* prev;
} list; 


list* head=NULL;
list* tail=NULL;
 void updatetail(list* head,list** tailptr)
 {
	 list* temp=head;
	 if(temp->next==NULL)
		  *tailptr=temp;
	  
	 else if(temp->next->next==NULL)
		 *tailptr=temp->next;
	 
	 else while(temp->next!=NULL)
		 temp=temp->next;
	 
	 *tailptr=temp;
 }

 list* newnode(char ndata[50],list* nnext)
 {
	 list* newn = (list*)malloc(sizeof(list));
	 strcpy(newn->data,ndata);
	 newn->next=nnext;
	 
	 return newn;
 }

 list* insertfront(list* head,char ndata[50])
 {
	return newnode(ndata,head); 
 }

  list* insertlast(list* head,char ndata[50])
 {
	list* temp=head;
    if(temp==NULL)
		
       return newnode(ndata,NULL);
    else
	{
		while(temp->next!=NULL)
	      temp=temp->next;
	      temp->next=newnode(ndata,NULL);
          return head;
    }   
	 
	 
 }

 void deletefront(list** point)
 {
	 *point=(*point)->next;
 }
 void deletelast(list* head)
 {
	list* temp=head;
	while(temp->next->next!=NULL)
		temp=temp->next;
	temp->next=NULL;
	updatetail(head,&tail);
 }
 void printlist(list* head)
 {
	 list* temp=head;
	 while(temp!=NULL)
	 {
		 printf("%s ",temp->data);
	    temp=temp->next;
		
	 }
	 printf("\n");
 }
 
 void printrev(list* head)
{
	list* temp=head;
	if(temp==NULL)
		return;
	else 
	{
		printrev(temp->next);
		printf("%s ",temp->data);
	}
	
}

void deletelist(list** point)
{
	*point=NULL;
}


void push(list* head,char key[50])
{
	insertfront(head,key);
}

char*  pop(list* top)
{
	list* temp=top;
	deletefront(&head);
	return temp->data;
	
}

char*  top(list* top)
{
	list* temp=top;
	//deletefront(&head);
	return temp->data;
	
}
