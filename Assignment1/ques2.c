#include<stdio.h>


typedef struct queue {
	int data[100];
	int front;
    int rear;
	} Queue ;
int isEmpty(Queue* );
void enqueue(Queue* Q,int key)
{
 if(Q->rear<100)
 {
	 if(Q->rear==-1)
        Q->front=0;
  
   Q->rear=(Q->rear+1)%100;
   Q->data[Q->rear]=key;
 }   
   else printf("Data Overflow\n");
	   
}

int dequeue(Queue* Q)
{
	if(!isEmpty(Q))
	{ 
     if(Q->front>-1 && Q->front<100)
	 {  
        int temp=Q->data[Q->front];
	    Q->front=(Q->front+1)%100;
		return temp;
	}}
	 else printf("No data present\n");
		 return 0;
}	

int isEmpty(Queue* Q) 
{
	if(Q->front==-1)
	return 1;	
	if(Q->front==(Q->rear+1)%100)
      return 1;
    
	
	return 0;
}		
 
int isFull(Queue* Q)
{ 
   
	if(Q->front==0 && Q->rear==98)
		return 1;
	
	if(Q->front==(Q->rear+2)%100)
       return 1;
   
    return 0;
} 
int welcome();

 	 Queue Q1;
     Queue Q2;
	 
	 Queue* q1=&Q1;
     Queue* q2=&Q2;
	 
void push(int key)
{
	enqueue(q2,key);
	
	while(!isEmpty(q1))
	{
		enqueue(q2,dequeue(q1));
	}	
	Queue* t=q1;
	q1=q2;
	q2=t;
} 
int top()
{
	if(isEmpty(q1))
		
		{
			printf("No data present\n");
		    return 0;
		}
	return q1->data[q1->front];
}
	 
int pop()
{
 return dequeue(q1);	
}


	 
void main()
{
	 Q1.front=-1;
     Q1.rear=-1;
     Q2.front=-1;
     Q2.rear=-1;
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
	                      enqueue(&Q1,key);goto QueueOP;
	              case 2: printf("%d\n",dequeue(&Q1));goto QueueOP;
				  case 3: break;
	          }
	 case 2:  StackOP:
	          printf("Operations available\n0 Top\n1 Push\n2 Pop \n3 Exit\n");
	          int l;
	          scanf("%d",&l);
	          switch(l)
			  {    
			      case 0: printf("%d\n",top()); goto StackOP;
				  case 1: printf("Enter data\n");
	                      int key;
						  scanf("%d",&key);
	                      push(key);goto StackOP;
	              case 2: printf("%d\n",pop());goto StackOP;
				  case 3: break;
	          }
	 
	 }
			
	      
	return 3;
}


	