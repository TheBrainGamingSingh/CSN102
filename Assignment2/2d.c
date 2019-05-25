#include<stdio.h>
#include<stdlib.h>
#define M 99999999

typedef struct file
{
 int data[4];

 struct tfile* next;
  
} file; 

typedef struct tfile
{
 int data[5];

 //struct file* next;
  
} tfile; 

file* head[10];
file **headptr=NULL;
file* newnode(file*);
tfile* tail[10];
tfile** tailptr;
int counter[10];
int toggle[10];

void tprinter(tfile*);
file* newnode(file* nnext)
 {
	 file* newn = (file*)malloc(sizeof(file));
	 newn->data[0]=M;
	 newn->data[1]=M;
	 newn->data[2]=M;
	 newn->data[3]=M;
	
	 newn->next=nnext;
	 
	 return newn;
 }
 
 
tfile* newtnode()
 {
	 tfile* newn = (tfile*)malloc(sizeof(tfile));
	 newn->data[0]=M;
	 newn->data[1]=M;
	 newn->data[2]=M;
	 newn->data[3]=M;
	 newn->data[4]=M;
	
	 
	 return newn;
}

void insert(int key)
{        

			int j=0;
			 if(key<0) 
			   j=((-1)*key)%10;
		      else 
				 j=key%10;
			 headptr=&head[j];
			 tailptr=&tail[j];

			if(toggle[j]==0)  
				{ 
			         *tailptr=newtnode();
			          counter[j]++;
					//  tfile*temp = *tailptr;
				     *headptr=(file*)(*tailptr);
					 (*tailptr)->data[0]=key;
				  	  toggle[j]++;	
				}
	        else if(toggle[j]<=4)
				{
					(*tailptr)->data[toggle[j]]=key;
				}
			else if(toggle[j]==5)
			{
					toggle[j]=0;
					file* temp=newnode(NULL);
					for(int i=0 ; i<4 ; i++)
						temp->data[i]=(*tailptr)->data[i];
			
				tfile* node=newtnode();
					temp->next=node;
					node->data[toggle[j]]=(*tailptr)->data[4];
					toggle[j]++;
					node->data[toggle[j]]=key;
					toggle[j]++;
					
			
				if((*headptr)==(*tailptr))
					*headptr=temp;
				else
				{
					file* walker=*headptr;
					while(walker->next!=(*tailptr))
					 {
						walker=walker->next;
					 }
					walker->next=temp;
				}
					free((*tailptr));
					(*tailptr)=node;
					counter[j]++;
			}
}

void printer(int key1)
{
  file* point=*headptr;	
  if(point==(*tailptr))
	{
	  for(int i=0;i<toggle[key1];i++)
	  printf("%d ",(*tailptr)->data[i]);
	}  
  else
	{
		while(point->next!=(*tailptr))
		{
			for(int i=0;i<4;i++)
				printf("%d ",point->data[i]);
		
		 point=point->next;
		}
		
		if(point->next==(*tailptr))
		{
		
			for(int i=0;i<4;i++)
				printf("%d ",point->data[i]);
			for(int i=0;i<toggle[key1];i++)
				printf("%d ",(*tailptr)->data[i]);
		}
	}
	 
  
}	
  void main()
 {  

	int i=0;
	  
	  Operations:
	
      printf("Operations Available \n1 Enter data\n2 Print data\n3 Exit\n");	
      scanf("%d",&i);
   	  
	  switch(i)
	{
	  
	  case 1: printf("Enter an integer\n");
	          int key=0;
              scanf("%d",&key);
			  insert(key);
			  goto Operations;
	  case 2: printf("Enter a digit\n");
	          int key1=0;
			  scanf("%d",&key1);
			 
			 headptr=&head[key1];
			 tailptr=&tail[key1];	
				
			
	         
			  if((*headptr)!=NULL) 
			 {
			   printf("Data: ");
			   printer(key1);
		       printf("\nNumber of files: %d\n",counter[key1]);
			 }
			 else printf("No Data\n");
			 goto Operations;
	 
	 case 3: return;
	} 		  
	  
}	  