#include<stdio.h>
#include<stdlib.h>

struct file
{
	int data[4];
	struct array* next;
};
typedef struct file* fptr;
fptr start[10];
int f[10],i[10]={0};
struct array
{
	int data[5];
};
typedef struct array* eptr;
eptr temp[10];

void insert(int num, int t)
{
	if(i[t]==0)
	{
		temp[t]=(eptr)(malloc(sizeof(struct array)));
		f[t]++;
		start[t]=(fptr)(temp[t]);
		temp[t]->data[i[t]++]=num;
	}
	else if(i[t]<=4)
	{
		temp[t]->data[i[t]++]=num;
	}
	else if(i[t]==5)
	{
		i[t]=0;
		fptr dum=(fptr)(malloc(sizeof(struct file)));
		for(int k=0 ; k<4 ; k++)
		{
			dum->data[k]=temp[t]->data[k];
		}
		eptr node=(eptr)(malloc(sizeof(struct array)));
		dum->next=node;
		node->data[i[t]++]=temp[t]->data[4];
		node->data[i[t]++]=num;
		if(start[t]==temp[t])
			start[t]=dum;
		else
		{
			fptr new=start[t];
			while(new->next!=temp[t])
			{
				new=new->next;
			}
			new->next=dum;
		}
		free(temp[t]);
		temp[t]=node;
		f[t]++;
	}
}
void display(int t)
{
	fptr dum=start[t];
	if(start[t]==NULL)
		printf("\nNo number with unit place %d exists. \n\n",t);
	else if(start[t]==temp[t])
	{
		for(int j=0 ; j<i[t] ; j++)
			printf("%d ",temp[t]->data[j]);
	}
	else
	{
		while(dum->next!=temp[t])
		{
			for(int j=0 ; j<4 ; j++)
			{
				printf("%d ",dum->data[j]);
			}
			dum=dum->next;
		}
		
		if(dum->next==temp[t])
		{
			int j;
			for(j=0 ; j<4 ; j++)
				printf("%d ",dum->data[j]);
			for(j=0 ; j<i[t] ; j++)
				printf("%d ",temp[t]->data[j]);
		}
	}
	printf("\nNo. of files : %d\n\n",f[t]);
}

void main()
{
	printf("\n1.Insert \n2.Print \n3.Exit\n");
	int n;
	scanf("%d",&n);
	switch(n)
	{
		case 1:
		{
		 printf("\nEnter number : ");
		 int num,t;
		 scanf("%d",&num);
		 if(num>=0)
			t=num%10;
		 else
		 {
			num=num*(-1);
			t=num%10;
			num=-1*num;
		 }
		 insert(num,t);
		 main();
		 break;
		}
		case 2:
		{
			printf("\nEnter the unit place of the numbers to be displayed : ");
			int n1;
			scanf("%d",&n1);
			display(n1);
			main();
			break;
		}
		case 3: exit(1);
	}
}
