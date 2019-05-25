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
int welcome();
void updatetail(list*,list**);
list* newnode(int ,list*);
list* insertfront(list*,int);
list* insertlast(list*,int);
void deletefront();
void deletelast(list*);
void printlist(list*);
void printrev(list*);
void deletelist(list**); 

void push(int key)
{
	if(head==NULL)
		head=tail=insertlast(head,key);
	else
		head=insertfront(head,key);
}

int pop()
{
	if(head!=NULL)
	{
		int temp=head->data;
	  deletefront(&head);
	    return temp;
	}
	else return -1;
}

int top()
{
	if(head!=NULL)
	{
		int temp=head->data;
	  //deletefront(&head);
	    return temp;
	}
	else return -1;
}
void enqueue(int key)
{
	
	if(head==NULL)
	{
		head=insertfront(head,key);
		tail=head;
    }
	else
		tail->next=insertlast(head,key);	
}
int dequeue()
{
	if(head!=NULL)
	{
		int temp=head->data;
	    deletefront();
	    return temp;
	}
	else return -1;
}

int front()
{
	if(tail!=NULL)
	return tail->data;
    else return -1;

}

int rear()
{
	if(head!=NULL)
	return head->data;
    else
		return -1;
}
/* void updatetail(list* head,list** tailptr)
 {
	 list* temp=head;
	 if(temp->next==NULL)
		  *tailptr=temp;
	  
	 else if(temp->next->next==NULL)
		 *tailptr=temp->next;
	 
	 else while(temp->next!=NULL)
		 temp=temp->next;
	 
	 *tailptr=temp;
 }*/

 list* newnode(int ndata,list* nnext)
 {
	 list* newn = (list*)malloc(sizeof(list));
	 newn->data=ndata;
	 newn->next=nnext;
	 
	 return newn;
 }

 list* insertfront(list* head,int ndata)
 { 
	return newnode(ndata,head); 
 }

  list* insertlast(list* tail,int ndata)
 {
	/*list* temp=head;
    if(temp==NULL)
		
       return newnode(ndata,NULL);
    else
	{
		while(temp->next!=NULL)
	      temp=temp->next;
	      temp->next=newnode(ndata,NULL);
          return head;
    }   */
	 tail->next=newnode(ndata,NULL);
	 return tail->next;
 }

 
 void deletefront()
 {
	 head=head->next;
 }
 void deletelast(list* head)
 {
	list* temp=head;
	while(temp->next->next!=NULL)
		temp=temp->next;
	temp->next=NULL;

 }
 void printlist(list* head)
 {
	 list* temp=head;
	 while(temp!=NULL)
	 {
		printf("%d ",temp->data);
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
		printf("%d ",temp->data);
	}
	
}

void deletelist(list** point)
{
	*point=NULL;
}

void main()
{

  int m=0;
   do{
	   
	   m=welcome();
   }while(m!=3) ;
}	  
int welcome()
{
    printf("What data structure should be used?\n1 Queue\n2 Stack\n3 Exit\n");
    int i;
	scanf("%d",&i);

		
		
	 switch(i)
	 { 
	  case 1: QueueOP:
	          printf("Operations available\n1 Enqueue\n2 Dequeue \n3 Exit\n");
	          int j;
	          scanf("%d",&j);
	          switch(j)
			  {
				  case 1: printf("Enter data\n");
	                      int key;
						  scanf("%d",&key);
	                      enqueue(key);goto QueueOP;
	              case 2: printf("%d\n",dequeue());goto QueueOP;
				  case 3: break;
	          }
	 case 2:  StackOP:
	          printf("Operations available\n0 Top\n1 Push\n2 Pop \n3 Exit\n");
	          int l;
	          scanf("%d",&l);
	          switch(l)
			  {    
			      case 0: top(); goto StackOP;
				  case 1: printf("Enter data\n");
	                      int key;
						  scanf("%d",&key);
	                      push(key);goto StackOP;
	              case 2: pop();goto StackOP;
				  case 3: break;
	          }
	 
	 }
			
	      
	return 3;
}
