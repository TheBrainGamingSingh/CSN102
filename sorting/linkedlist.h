#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list
{
 char data[20];

 struct list* next;
 struct list* prev;
 
} list; 

list* head=NULL;
list* tail=NULL;
list* newnode(char[],list*,list*);
list* insertfront(list*,char []);

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
 
  list* insertlast(list* end,char ndata[20])
 { 
   /* list* temp=start;
	if(temp==NULL)
		return newnode(ndata,NULL);
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode(ndata,NULL); 
		return start;
    }*/
   list* temp=newnode(ndata,NULL,end);
   if(end!=NULL)
	   end->next=temp;
	return temp;
 }
void updatetail()
{
	if(head->next==NULL || head==NULL)
		tail=head;
	return;
}
void updatehead()
{
	if(tail->prev==NULL || tail==NULL)
		head=tail;
	return;
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
 
  list* deletelast(list* end)
 { 
    
   /* list* temp=start;
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
	}*/
   list* temp=end;
   if(temp==NULL)
	{
		printf("List already empty\n");
		return temp;
	}
	else if(temp->prev==NULL)
	{
		return NULL;
	}
	else
	{  
    end->prev->next=NULL;
    temp=end->prev;
    free(end);
	return temp;
	}
   
 }
 //printf("\nHead=%s\nTail=%s",head->data,tail->data);
 
 void menu()
 {
	 	 

	          ListOP:
	          printf("\nOperations available\n1 Insert at Front\n2 Insert at Last\n3 Delete the Front\n4 Delete the Last\n5 Print\n7 Exit\n");
	          int w;
	          scanf("%d",&w);
	          switch(w)
			  {
				  case 1: printf("Enter data\n");
	                      char key[20];
						  scanf("%s",&key);
	                      head=insertfront(head,key);
						  updatetail();
     					  printf("List:");
						  printlist(head);
						  printf("\nHead=%s\nTail=%s",head->data,tail->data);
						  goto ListOP;
	           
      			  case 2: printf("Enter data\n");
	                      char key1[20];
						  scanf("%s",&key1);
	                      tail=insertlast(tail,key1);
						  updatehead();
						  printf("List:");
						  printlist(head);
						  printf("\nHead=%s\nTail=%s",head->data,tail->data);
						  goto ListOP;
				
				  case 3: if(head->next==NULL)
						  { 
					       head=NULL;
						   tail=NULL;
						   printf("List:");
			               printlist(head);
						    goto ListOP;
						  }
				          
						  if(head!=NULL ){
				          head=deletefront(head);
                          updatetail();						  
				          printf("List:");
			              printlist(head);}
						
						  else printf("List empty\n");
						  printf("\nHead=%s\nTail=%s",head->data,tail->data);
						  goto ListOP;
				  case 4: if(tail->prev==NULL)
						  { 
					       head=NULL;
						   tail=NULL;
						   printf("List:");
			               printlist(head);
						   goto ListOP;
						  }
				  
				          if(head!=NULL) {
				           tail=deletelast(tail);
 						   updatehead();
						   printf("List:");
				           printlist(head); }    
						
						   else printf("List empty\n");
						   printf("\nHead=%s\nTail=%s",head->data,tail->data);
 						  goto ListOP;
				  case 5: if(head!=NULL)
				           {  
 					           printf("List:");
			                   printlist(head);	
			               }
						   else printf("List empty\n");
						   printf("\nHead=%s\nTail=%s",head->data,tail->data);
 						  goto ListOP;
                 			 
				  case 7: return ;
	          }
 }
 