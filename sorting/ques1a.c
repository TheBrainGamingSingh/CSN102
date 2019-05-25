#include<stdio.h>
#include<stdlib.h>


typedef struct list
{
 int data;

 struct list* next;
 //struct list* prev;
 
} list; 

list* head=NULL;
list* tail=NULL;
list* newnode(int,list*);
list* insertfront(list*,int);
int welcome();

 list* newnode(int ndata,list* nnext)
 {
	 list* newn = (list*)malloc(sizeof(list));
	 newn->data=ndata;
	 newn->next=nnext;
	 
	 return newn;
 }
 
 list* insertfront(list* start,int ndata)
 { 
	return newnode(ndata,start); 
 }
 
 list* insertlast(list* start,int ndata)
 { 
    list* temp=start;
	if(temp==NULL)
		return newnode(ndata,NULL);
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode(ndata,NULL); 
		return start;
	}

 }
 
 void printlist(list* start)
 { 
    if(start==NULL)
		return;
	 list* temp=start;
	 while(temp!=NULL)
	 {
		printf("%d ",temp->data);
	    temp=temp->next;
		
	 }
	 printf("\n");
 }
 
 list* deletefront(list* start)
 {
	 list* temp=start;
	 temp=temp->next;
	 free(start);
	 
	 return temp;
 } 
 
 list* deleteafter(list* start,list* after)
 {
	 list* temp=after;
	 temp->next=temp->next->next;
	 free(after);
	 
	 return start;
 } 
  
 list* deletelast(list* start)
 { 
    list* temp=start;
	if(temp==NULL)
	{
		printf("List already empty\n");
		return start;
	}	
	else if(temp->next==NULL)
	{
		return NULL;//
	}
	else
	{
		while(temp->next->next!=NULL)
			temp=temp->next;
		temp->next=NULL;
		return start;
	}

 }

//implementing queue 
 void enqueue(int key)
 {
	 head=insertlast(head,key);
	 printf("Queue:");
	 printlist(head);
	
 }
 
 int dequeue()
 {
	 if(head!=NULL)
	 {
		 int temp= head->data;
	     head=deletefront(head);
	     printf("Queue:");
	     printlist(head);
	     return temp;
	 }
	 else printf("Data Underflow\n");
	 return 0;
 }
//stack implement

void push(int key)
{
	head=insertfront(head,key);
	 printf("Stack:");
	 printlist(head);
}
 
 int top()
 {
	  if(head!=NULL)
	 {
		 int temp= head->data;
	    // head=deletefront(head);
	     printf("Stack:");
	     printlist(head);
	     return temp;
	 }
	 else printf("Data Underflow\n");
	 return 0; 
 }
 
 int pop()
 {
		 if(head!=NULL)
	 {
		 int temp=head->data;
	     head=deletefront(head);
	     printf("Stack:");
	     printlist(head);
	     return temp;
	 }
	 else printf("Data Underflow\n");
	 return 0; 
 }
 
 void printrev(list* head)
{
	list* temp=head;
	if(temp==NULL)
		return;
	else 
	{
		printrev(temp->next);
		printf("%d ",temp->data);
		return;
	}
	
} 
//driver program 
 void main()
{

  int m=0;
   do{
	   
	   m=welcome();
   }while(m!=3) ;
   return;
}	  
int welcome()
{
    printf("What operation should be used? (for integers)\n0 List\n1 Queue\n2 Stack\n3 Exit\n");
    int i;
	scanf("%d",&i);

		
		
	 switch(i)
	 { 
	  case 0: ListOP:
	          
	          printf("\nOperations available\n1 Insert at Front\n2 Insert at Last\n3 Delete the Front\n4 Delete the Last\n5 Print\n6 Print in reverse order\n7 Exit\n");
	          int w;
	          scanf("%d",&w);
	          switch(w)
			  {
				  case 1: printf("Enter data\n");
	                      int key;
						  scanf("%d",&key);
	                      head=insertfront(head,key);
						 
     					  printf("List:");
						  printlist(head);
						  goto ListOP;
	           
      			  case 2: printf("Enter data\n");
	                      int key1;
						  scanf("%d",&key1);
	                      head=insertlast(head,key1);
						  
						  printf("List:");
						  printlist(head);
						  goto ListOP;
				
				  case 3: if(head!=NULL){
				          head=deletefront(head); 
				          printf("List:");
			              printlist(head);}  else printf("List empty\n");
						  goto ListOP;
				  case 4: if(head!=NULL) {
				           head=deletelast(head);
 						   
						   printf("List:");
				           printlist(head); }    
						   else printf("List empty\n");                    
 						  goto ListOP;
				  case 5: if(head!=NULL)
				           {  
 					           printf("List:");
			                   printlist(head);	
			               }
						   else printf("List empty\n");
 						  goto ListOP;
                  case 6: if(head!=NULL)
				           {   printf("List:");
			                   printrev(head);	
			               }
						   else printf("List empty\n");
 						  goto ListOP;				 
				  case 7: return 3;
	          }
			  return 1;
	          
	  case 1: QueueOP:
	          printf("Operations available\n1 Enqueue\n2 Dequeue \n3 Exit\n");
	          int j;
	          scanf("%d",&j);
	          switch(j)
			  {
				  case 1: printf("Enter data\n");
	                      int key;
						  scanf("%d",&key);
	                      enqueue(key);
						  goto QueueOP;
	              case 2: dequeue();
				          goto QueueOP;
				  case 3: return 3;
	          }
			  return 1;
	 case 2:  StackOP:
	          printf("Operations available\n0 Top\n1 Push\n2 Pop \n3 Exit\n");
	          int l;
	          scanf("%d",&l);
	          switch(l)
			  {    
			      case 0: top();
          				  goto StackOP;
				  case 1: printf("Enter data\n");
	                      int key;
						  scanf("%d",&key);
	                      push(key);
						  goto StackOP;
	              case 2: pop();
				          goto StackOP;
				  case 3: return 3;
	          }
			  return 2;
     case 3: return 3;	 
	 }	
}	 
	 