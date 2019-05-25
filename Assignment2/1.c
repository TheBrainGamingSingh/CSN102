#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list
{
 char data[20];

 struct list* next;
 //struct list* prev;
 
} list; 

list* head=NULL;
list* tail=NULL;
list* newnode(char[],list*);
list* insertfront(list*,char []);
int welcome();

 list* newnode(char ndata[20],list* nnext)
 {
	 list* newn = (list*)malloc(sizeof(list));
	 strcpy(newn->data,ndata);
	 newn->next=nnext;
	 
	 return newn;
 }
 
 list* insertfront(list* start,char ndata[20])
 { 
	return newnode(ndata,start); 
 }
 
 list* insertlast(list* start,char ndata[20])
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
		printf("%s ",temp->data);
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
		return NULL;
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
 void enqueue(char key[20])
 {
	 head=insertlast(head,key);
	 printf("Queue:");
	 printlist(head);
	
 }
 
 char* dequeue()
 {
	 if(head!=NULL)
	 {
		 char temp[20];
		 strcpy(temp,head->data);
	     head=deletefront(head);
	     printf("Queue:");
	     printlist(head);
	     return temp;
	 }
	 else printf("Data Underflow\n");
	 return NULL;
 }
//stack implement

void push(char key[20])
{
	 head=insertfront(head,key);
	 printf("Stack:");
	 printlist(head);
}
 
 char* top()
 {
	  if(head!=NULL)
	 {
		 char temp[20];
		 strcpy(temp,head->data);
	    // head=deletefront(head);
	     printf("Stack:");
	     printlist(head);
	     printf("Top: %s\n",temp);
		 return temp;
	 }
	 else printf("Data Underflow\n");
	 return NULL; 
 }
 
 char* pop()
 {
		 if(head!=NULL)
	 {
		 char temp[20];
		 strcpy(temp,head->data);
	     head=deletefront(head);
	     printf("Stack:");
	     printlist(head);
	     return temp;
	 }
	 else printf("Data Underflow\n");
	 return NULL; 
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
    printf("What operation should be used? (for both integers and strings this works)\n0 List\n1 Queue\n2 Stack\n3 Exit\n");
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
	                      char key[20];
						  scanf("%s",&key);
	                      head=insertfront(head,key);
						 
     					  printf("List:");
						  printlist(head);
						  goto ListOP;
	           
      			  case 2: printf("Enter data\n");
	                      char key1[20];
						  scanf("%s",&key1);
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
	                      char key[20];
						  scanf("%s",&key);
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
	                      char key[20];
						  scanf("%s",&key);
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
	 