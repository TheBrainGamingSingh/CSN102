#include<stdio.h>
#include<stdlib.h>

typedef struct file
{
	int data[4];
	struct tfile* next;
} file;
typedef struct file* fptr;


fptr head[10];
int count[10],toggle[10]={0};
typedef struct tfile
{
	int data[5];
} tfile;

typedef struct tfile* tptr;
tptr tail[10];

void insert(int key, int j)
{
	if(toggle[j]==0)
	{
		tail[j]=(tptr)(malloc(sizeof(struct tfile)));
		count[j]++;
		head[j]=(fptr)(tail[j]);
		tail[j]->data[toggle[j]++]=key;
	}
	else if(toggle[j]<=4)
	{
		tail[j]->data[toggle[j]++]=key;
	}
	else if(toggle[j]==5)
	{
		toggle[j]=0;
		fptr temp=(fptr)(malloc(sizeof(struct file)));
		
		for(int i=0;i<4;i++)
			temp->data[i]=tail[j]->data[i];
	
		tptr node=(tptr)(malloc(sizeof(struct tfile)));
		temp->next=node;
		node->data[toggle[j]++]=tail[j]->data[4];
		node->data[toggle[j]++]=key;
		
		if(head[j]==tail[j])
			head[j]=temp;
		else
		{
			fptr walker=head[j];
			while(walker->next!=tail[j])
			{
				walker=walker->next;
			}
			walker->next=temp;;
		}
		free(tail[j]);
		tail[j]=node;
		count[j]++;
	}
}

void printer(int j)
{
	
	fptr point=head[j];
	if(head[j]==NULL)
		printf("No data\n");
	else if(head[j]==tail[j])
	{
		for(int i=0;i<toggle[j];i++)
			printf("%d ",tail[j]->data[i]);
    }
	
	else
	{
		while(point->next!=tail[j])
		{
			for(int i=0;i<4;i++)
			{
				printf("%d ",point->data[i]);
			}
			point=point->next;
		}
		
		if(point->next==tail[j])
		{
			
			for(int i=0;i<4;i++)
				printf("%d ",point->data[i]);
			for(int i=0;i<toggle[j];i++)
				printf("%d ",tail[j]->data[i]);
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
			  int j=0;
			
			  if(key<0) 
			   j=((-1)*key)%10;
		      else 
				 j=key%10;
			  insert(key,j);
			  goto Operations;
	  case 2: printf("Enter a digit\n");
	          int key1=0;
			  scanf("%d",&key1);
               printf("Data:");
			   printer(key1);
		       printf("\nNumber of files: %d\n",count[key1]);
			 
			 
			 goto Operations;
	 
	 case 3: return;
	} 		  
	  
}	  