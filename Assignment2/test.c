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

 list* insertafter(list* after,char ndata[20])
 {
  	 
  list* temp=newnode(ndata,after->next,after);
  after->next=temp;
  if(temp->next!=NULL)
  temp->next->prev=temp; 
  return after; 
 }

 list* search(list* start,char key[20])
 {
	  { 
    if(start==NULL)
	{
		printf("Key not found\n");
		return NULL;
	}	
	 list* temp=start;
	 while(temp!=NULL)
	 {
		if(strcmp(temp->data,key)==0)
			return temp;
	    else temp=temp->next;
		
	 }
	printf("Key not found\n");
	return NULL;
 }
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
 list* deletekey(list* start,char key[20])
 {
	
    if(start==NULL)
	{
		printf("Key not found\n");
		return start;
	}	
	 list* temp=start;
	 while(temp!=NULL)
	 {
		if(strcmp(temp->data,key)==0)
		{
			if(temp->prev!=NULL)
				temp->prev->next=temp->next;
			if(temp->next!=NULL)
			 temp->next->prev=temp->prev;
		    free(temp);
		  return start;
		}
	    else temp=temp->next;
	}
	
	printf("Key not found\n");
	return start;
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
 
 void main()
 {
	 	 

	          ListOP:
	          printf("\nOperations available\n0 Insert after\n1 Insert at Front\n2 Insert at Last\n3 Delete the Front\n4 Delete the Last\n5 Print\n6 Delete key\n7 Exit\n");
	          int w;
	          scanf("%d",&w);
	          switch(w)
			  {   
			      case 0: printf("Enter key\n");
	                      char key2[20];
						  scanf("%s",&key2);
				          list* after=search(head,key2);
						  if(after!=NULL)
						  {  
					         printf("Enter data\n");
	                         char key3[20];
						     scanf("%s",&key3);
			                 after=insertafter(after,key3);
						  } else printf("Enter Valid Key\n");
						  goto ListOP;
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
				
				  case 3:if(head!=NULL)
				         { if(head->next==NULL)
						  { 
					       head=NULL;
						   tail=NULL;
						   printf("List:");
			               printlist(head);
						    goto ListOP;
						  }
				          
						  else{
				          head=deletefront(head);
                          updatetail();						  
				          printf("List:");
			              printlist(head);}
						 }
						  else printf("List empty\n");
						  printf("\nHead=%s\nTail=%s",head->data,tail->data);
						  goto ListOP;
				  case 4: if(tail!=NULL)
				          { 
					      if(tail->prev==NULL)
						  { 
					       head=NULL;
						   tail=NULL;
						   printf("List:");
			               printlist(head);
						   goto ListOP;
						  }
				  
				          else {
				           tail=deletelast(tail);
 						   updatehead();
						   printf("List:");
			               printlist(head); } }   
						
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
                 case 6 : printf("Enter key\n");
	                      char key5[20];
						  scanf("%s",&key5);	
						   if(head!=NULL)
						  {  
					         if(search(head,key5)!=NULL)
			                  head=deletekey(head,key5);
						  else printf("Enter Valid Key\n");
						  } 
						  updatetail();	
						  printf("List:");
			              printlist(head); 
						  printf("\nHead=%s\nTail=%s",head->data,tail->data);
						  goto ListOP;
				  case 7: return ;
	          }
 }
 