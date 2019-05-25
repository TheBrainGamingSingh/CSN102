#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct playlist{
 //char side;
 char song_name[20];
 char singer_name[20];
 char movie_name[20];
 struct playlist* next;
 struct  playlist* prev;

} playlist;

playlist* headA=NULL;
playlist* tailA=NULL;

playlist* headB=NULL;
playlist* tailB=NULL;

playlist* newsong(char song[20],char singer[20],char movie[20],playlist* nnext,playlist* nprev)
{
  playlist* newn = (playlist*)malloc(sizeof(playlist));
  strcpy(newn->song_name,song);
  strcpy(newn->singer_name,singer);
  strcpy(newn->movie_name,movie);
  newn->next=nnext;
  newn->prev=nprev;

  return newn;
}

/* playlist* insertfinder(char side,char song[20],playlist* start)
{
  playlist* temp=start;
  while(temp!=NULL &&  (strcmp(song,temp->song_name)>=0))
   temp->temp->next;
}*/

playlist* insertfront(char song[20],char singer[20],char movie[20],playlist* start)
{
	return newsong(song,singer,movie,start,NULL);	
}
void  insertafter(char song[20],char singer[20],char movie[20],playlist** node)
{
	printf("check");
	playlist* after=*node;
	playlist*temp=newsong(song,singer,movie,NULL,NULL);	
	temp->next=after->next;
	temp->prev=after;
	after->next->prev=temp;
	after->next=temp;
	printf("check");
}
void printinfo(playlist* info)
{
 	if(info!=NULL)
	printf("\n\t\t\t\t'%s'\n\t\tSinger: %s\n\t\tMovie/Album: %s\n",info->song_name,info->singer_name,info->movie_name);
    else return;
}
void main()
{
 //printf("hello");
 
 char A[20]="High End";
 char B[20]="Diljit Dosanjh";
 char C[20]="Confidential";

 char D[20]="Weekend";

 
 headA=insertfront(A,B,C,headA);
 printinfo(headA);
 headA=insertfront(D,B,C,headA);
 printinfo(headA->next);
 printinfo(headA->next->prev);
  return;
}

