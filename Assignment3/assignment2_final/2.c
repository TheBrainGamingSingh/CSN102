#include<stdio.h>
#include<stdlib.h>
#define M 99999999
typedef struct file
{
	int data[4];
	struct file* next;
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
	if(count[j]<=1)
	{
		if(toggle[j]==0)
		{
		tail[j]=(tptr)(malloc(sizeof(struct tfile)));
		count[j]++;
		head[j]=(fptr)(tail[j]);
		tail[j]->data[toggle[j]++]=key;
		tail[j]->data[toggle[j]]=M;
		}
		else if(toggle[j]<=4)
		{
		tail[j]->data[toggle[j]++]=key;
			if(toggle[j]!=5)
				tail[j]->data[toggle[j]]=M;
		}
	
		else if(toggle[j]==5)
		{
		toggle[j]=0;
		fptr temp=(fptr)(malloc(sizeof(struct file)));
        temp->next=(fptr)(head[j]);
		temp->data[toggle[j]++]=key;
		temp->data[toggle[j]]=M;
		head[j]=temp;
		
		count[j]++;
		}
	}
    
    else if(count[j]>1)
    {
	   if(toggle[j]<4)
		{
		 head[j]->data[toggle[j]++]=key;
		if(toggle[j]!=4)
		 head[j]->data[toggle[j]]=M;
		
		}

	   else if(toggle[j]==4)
	   {
		toggle[j]=0;
		fptr temp=(fptr)(malloc(sizeof(struct file)));
        temp->next=(fptr)(head[j]);
		temp->data[toggle[j]++]=key;
		temp->data[toggle[j]]=M;
		head[j]=temp;
		
		count[j]++;
	   }
		
	
	}
}

void printer(fptr start,int j)
{
	//for(int i=0;i<4;i++)
	//printf("this is the first element %d ",start->data[0]);
	//
	if(start==NULL)
       printf("No data\n");
	else if(start==tail[j])
	{
		for(int i=0;i<toggle[j];i++)
			printf("%d ",tail[j]->data[i]);
    }
	else if(start->next!=tail[j])
	{
			printer(start->next,j);
	        for(int i=0;i<4;i++)
			{
				if(start->data[i]==M)
					break;
				else
				printf("%d ",start->data[i]);
			}
	}
    else if(start->next==tail[j])
		{
				for(int i=0;i<5;i++)
					printf("%d ",tail[j]->data[i]);
				
				for(int i=0;i<4;i++)
					if(start->data[i]==M)
					break;
				    else
					printf("%d ",start->data[i]);
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
			   printer(head[key1],key1);
		       printf("\nNumber of files: %d\n",count[key1]);
			 
			 
			 goto Operations;
	 
	 case 3: return;
	} 		  
	  
}	  			
		