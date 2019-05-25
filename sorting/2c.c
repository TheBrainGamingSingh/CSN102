#include<stdio.h>
#include<stdlib.h>
#define M 99999999

typedef struct file
{
 int data[4];

 struct file* next;
  
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
int count=0;
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

void printer(file* start)
{
	file* point=start;
		while(count>1)
		{
			
		for(int x=0;x<4;x++)
		printf("%d ",point->data[x]);
		count--;
		point=point->next;
		}
	 
	 	if(count==1)
	{
		tfile* point1=(tfile*) point;
	
    	for(int x=0;x<5;x++)
				  {
					 if(point1->data[x]!=M) 
       				  printf("%d ",point1->data[x]);
				     else break;
				  }	
	}

}

 void main()
 {  

	int i=0;
	  
	  Operations:
	
      printf("Operations Available \n1 Enter data\n2 Print data\n3 Exit\n");	
      scanf("%d",&i);
   	  
	  switch(i){
	  
	  case 1: 
	          printf("Enter an integer\n");
	          int key=0;
              int j=0;
			  scanf("%d",&key);
			  if(key<0) 
			   j=((-1)*key)%10;
		      else 
				 j=key%10;
			 headptr=&head[j];
			 tailptr=&tail[j];
			 
			if(!(*tailptr))
				*tailptr=newtnode();
			 
			tfile*temp=*tailptr;
			if(!(*headptr))
				*headptr=(file*)*tailptr;
			 
			if(counter[j]==0)  
				{ 
                  
			         for(int index=0;index<5;index++)
				          {
					         if(temp->data[index]==M)
					          {
								temp->data[index]=key;
								break;
							  }
							  
							  else if(index==4 && temp->data[4]!=M)
							  {
								 toggle[j]=1;
							  } 	  
				 		  }	
				}
			
			if(toggle[j]==1)
			{
				  if(counter[j]==0)
				   {
					*headptr=newnode((file*)*tailptr);
					file* temp1=*headptr;
					 for(int index=0;index<4;index++)
					   (temp1->data[index]=temp->data[index]);
				
					 temp->data[0]=temp->data[4];
					 
					 for(int index=1;index<5;index++)
					   temp->data[index]=M;
					  
					  toggle[j]=0;
					  counter[j]+=1;
				   }
                 if(counter[j]>0)
				 {
					 file* temp2=newnode((file*)*tailptr);
					
					 (*headptr)->next=temp2;
					 for(int index=0;index<4;index++)
					   (temp2->data[index]=temp->data[index]);
				
					 temp->data[0]=temp->data[4];
					 
					 for(int index=1;index<5;index++)
					   temp->data[index]=M;
					  
					  toggle[j]=0;
					  counter[j]+=1;
				 }
            }
            goto Operations;





      case 2: printf("Enter a digit\n");
	          int key1=0;
			  scanf("%d",&key1);
			  headptr=&head[key1];	
			  file* temp3= *headptr;
	          count=counter[j]+1;
			  if(temp3!=NULL) 
			  {
			   printf("Data: ");
			   printer(temp3);
		       count=0; 
			 
			  printf("\nNumber of files: %d\n",counter[j]+1);
			 }
			 else printf("No Data\n");
			  goto Operations;
	case 3: return;
	  }
 }	  
 