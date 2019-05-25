//sorted dll
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list
{
 char song_name[20];
 char singer_name[20];
 char movie_name[20];
 
 struct list* next;
 struct list* prev;
 
} list; 

list* headA=NULL;
//list* tailA=NULL;
list* headB=NULL;
//list* tailB=NULL;
list* newnode(char[],char[],char[],list*,list*);
 
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
		printf("Song: %s\nSinger: %s\nMovie: %s\n",temp->song_name,temp->singer_name,temp->movie_name);
	    temp=temp->next;
		
	 }
	 printf("\n");
 }
 void printinfo(list* info)
{
 	if(info!=NULL)
	printf("'%s'\nSinger: %s\nMovie/Album: %s\n",info->song_name,info->singer_name,info->movie_name);
    else return;
}
 
  void printsongs(list* start)
 { 
    if(start==NULL)
		return;
	 list* temp=start;
	 while(temp!=NULL)
	 {
		printf("Song: %s\n",temp->song_name);
	    temp=temp->next;
		
	 }
	 printf("\n");
 }

 list* newnode(char song[20],char singer[20],char movie[20],list* nnext,list* nprev)
 {
	 list* newn = (list*)malloc(sizeof(list));
	 //strcpy(newn->data,ndata);
	 strcpy(newn->song_name,song);
     strcpy(newn->singer_name,singer);
     strcpy(newn->movie_name,movie);
	 newn->next=nnext;
	 newn->prev=nprev;
	 
	 return newn;
 }

 list* insertfront(list* start,char song[20],char singer[20],char movie[20])
 { 
	return newnode(song,singer,movie,start,NULL); 
 }

void insert(char song[20],char singer[20],char movie[20],list** start) 
{
	//list empty
	if(*start==NULL)
		*start=newnode(song,singer,movie,NULL,NULL);
	
	  else if (strcmp((*start)->song_name,song)>0) 
	  {
        *start=insertfront(*start,song,singer,movie);
	  }
     else
	 {
        list* temp = *start;
        
        //searching the node
      while(temp->next!= NULL)
		  if(strcmp(temp->next->song_name,song)>0)
           break;
 	     else temp=temp->next;
        
		
		list* new=newnode(song,singer,movie,temp->next,temp);
        
		if (temp->next!=NULL)
            new->next->prev = new;
 
         temp->next=new;
    
    }
} 

void play(list* start)
{
	list*temp=start;
	PLAY: printf("Now Playing\n");
	
	int i;
	printf("\n"); 
	      printinfo(temp);
	      printf("\n1 Next Song\n2 Previous Song\n3 Back\n");
	fflush(stdin);	  
	scanf("%d",&i);	  
	switch(i)
	{
		case 1 : if(temp->next!=NULL)
		         temp=temp->next;
			     else printf("End of tape\n");
		         goto PLAY;
		case 2 : if(temp->prev!=NULL)
		         temp=temp->prev; 
			     else printf("Can't go back,this is the first song in the list\n");
		         goto PLAY;
		case 3 : return;
	}
}
void deletesong(list** start,char key[20])
 {
	
    if(*start==NULL)
	{
		printf("Song not found\n");
		return;
	}	
	 list* temp=*start;
	 while(temp!=NULL)
	 {
		if(strcmp(temp->song_name,key)==0) //song found
		{
			if(temp==*start)
		      *start=temp->next; 
			
			if(temp->prev!=NULL)//if song is not at head
				temp->prev->next=temp->next;
			
			if(temp->next!=NULL)//if song is not at tail
			 temp->next->prev=temp->prev;
		 
		 
		  free(temp);
		  return;
		}
	    else temp=temp->next;
	}
	
	printf("Song not found\n");
	return ;
 }

void updatesong(list** start,char key[20])
 {
	
    if(*start==NULL)
	{
		printf("Song not found\n");
		return;
	}	
	 list* temp=*start;
	 while(temp!=NULL)
	 {
		if(strcmp(temp->song_name,key)==0) //song found
		{
		  int j;
         UPDATE: printf("What do you want to update?\n1 Song Name\n2 Singer Name\n3 Movie Name\n4 Back\n");
		  scanf("%d",&j);
		  fflush(stdin);	
		  switch(j)
		  {
			  case 1:    printf("Enter Song Name\n");
						char song2[20];	
						
						 fflush(stdin); 
						 gets(song2);
						
 						 list* tempnew=newnode(song2,temp->singer_name,temp->movie_name,NULL,NULL);
						 deletesong(start,temp->song_name);
						 insert(tempnew->song_name,tempnew->singer_name,tempnew->movie_name,start);
						 free(tempnew);
						//strcpy(temp->song_name,song2);
                         goto UPDATE;
			  
			  case 2:   printf("Enter Singer Name\n");
						char singer2[20];
             			 
						 fflush(stdin);	
						 gets(singer2); 
						 
						 strcpy(temp->singer_name,singer2);
			             goto UPDATE;
			

    		  case 3:   printf("Enter Movie Name\n");	 
			            char movie2[20];	
			             
						 fflush(stdin);
						 gets(movie2);
						
						 strcpy(temp->movie_name,movie2);
						 goto UPDATE;
			  
			  case 4:    return;
		  }
		}
	    else temp=temp->next;
	}
	
	printf("Song not found\n");
	return ;
 }





void main()
{
	ListOP:
	          printf("\nOperations available\n1 Insert\n2 Delete\n3 Update\n4 Print\n5 Play\n6 Exit\n");
	          int w;
	          scanf("%d",&w);
			  list** head;
	          switch(w)
			  {
				  case 1: 
						{
						 char song[20];	
						 printf("Enter Song Name\n");
						 fflush(stdin); 
						 gets(song);
						 printf("Enter Singer Name\n");
						 char singer[20];	
						 gets(singer);
						 fflush(stdin);
						 printf("Enter Movie Name\n");
						 char movie[20];	
						 gets(movie);
						 fflush(stdin);
						 
						 head=sidecheck(); 
						 
						  insert(song,singer,movie,head);

						  goto ListOP;
						}
				case 2: {
         			     head=sidecheck(); 
				         if(*head!=NULL)
				           {  
					          printsongs(*head);	
 					          char song1[20];	
						      printf("Enter Song Name\n");
						      fflush(stdin); 
						      gets(song1); 
			                  deletesong(head,song1); 
			               }
						   else printf("Playlist empty\n");
						 
 						  goto ListOP;
						} 
				 case 3:{
         			     head=sidecheck(); 
				         if(*head!=NULL)
				           {  
					          printsongs(*head);	
 					          char song4[20];	
						      printf("Enter Song Name\n");
						      fflush(stdin); 
						      gets(song4); 
			                  updatesong(head,song4); 
			               }
						   else printf("Playlist empty\n");
						 
 						  goto ListOP;
						} 
				 
				 case 4: 
						{
         			     head=sidecheck(); 
				         if(*head!=NULL)
				           {  
 					          // printf("List:");
			                   printsongs(*head);	
			               }
						   else printf("Playlist empty\n");
						 
 						  goto ListOP;
						} 
				  case 5: head=sidecheck();
				          fflush(stdin);
 						   if(*head!=NULL)
				           {  
 					          // printf("List:");
			                   play(*head);	
			               }
						   else printf("Playlist empty\n");
						  
 						  goto ListOP;
						
					
                 case 6: return ;
                }
 
}