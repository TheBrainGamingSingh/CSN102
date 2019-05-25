#include<stdio.h>
#include<stdlib.h>
#define inf 9999
typedef struct NODE{
	int with;
	int wt;
	struct NODE*next;
}node;
typedef struct NODE2{
	int wt;
	int name[2];
}node2;
typedef node* ptr;
ptr costsAL[10],distanceAL[10];
node2 heap[45];
int heapCtr,visited[10],weights[10],v,reps[12];
void Union(int a,int b)
{
	int repA=find(a),repB=find(b),countA=0,countB=0,i;
	for(i=0;i<12;i++)
		if(find(i)==repA)
			countA++;
		else if(find(i)==repB)
			countB++;
	if(countA>countB)
		reps[find(b)]=find(a);
	else
		reps[find(a)]=find(b);
}
int find(int a)
{
	int start=reps[a];
	while(reps[start]!=start)
		start=reps[start];
	return start;
}
int vtd(int i)
{
	if(visited[i]==0)
		return 0;
	else 
		return 1;
}
int minimumIndex(int a[],int k)
{
	int i,min;
	for(i=0;i<k;i++)
		if(!vtd(i))
		{
			min=i;
			break;
		}
	for(i=0;i<k;i++)
		if(vtd(i)==0&&(a[i]<a[min]))
			min=i;
	return min;
}
void heapify(int i)
{
	int j=i;
	node2 temp;
	if(j>=heapCtr||(2*i+1>=heapCtr&&2*i+2>=heapCtr))//bug1
		return;
	else
	{
		int left=(heap[2*j+1]).wt,right=(heap[2*j+2]).wt,curr=(heap[j]).wt;
		if(2*i+2>=heapCtr)
			right=curr;
		if(2*i+1>=heapCtr)
			left==curr;//bug2
		if(left!=0&&left<curr&&left<right)
		{
			temp=heap[j];
			heap[j]=heap[2*j+1];
			heap[2*j+1]=temp;
		}
		else if(right!=0&&right<curr&&right<left)
		{
			temp=heap[j];
			heap[j]=heap[2*j+2];
			heap[2*j+2]=temp;
		}
		heapify(2*j+1);
		heapify(2*j+2);
	}
}
ptr newNode(int i, int j, int k)
{
	ptr PTR=(ptr)malloc(sizeof(node));
	PTR->with=j;
	PTR->wt=k;
	PTR->next=costsAL[i];
	return PTR;
}
void insert(ptr a,int i)
{
	node2 temp;
	temp.wt=a->wt;
	temp.name[1]=i;
	temp.name[0]=a->with;
	heap[heapCtr++]=temp;
	int k=heapCtr/2-1;
	if(heapCtr==1)//only one element in heap
		k=0;
	while(k>0)
	{
		heapify(k);
		k=(k-1)/2;
	}
	heapify(0);
}
node2 delete()
{
	node2 temp=heap[0];
	heap[0]=heap[--heapCtr];
	heapify(0);
	return temp;
}
main()
{
	//0-NAB char* name[12]={"NAB","IT","CSE","Admin","Civil","SPIC","Library","Meta","CC","ECE"};
	//1-IT
	//2-CSE
	//3-Admin
	//4-Civil
	//5-SPIC
	//6-Library
	//7-Meta
	//8-CC
	//9-ECE
	int i,j,loc1,loc2,chc,no=0;
	node2 edge;
	int costsAM[12][12]={{0,13,42,110,0,0,0,0,0,0},{13,0,0,0,0,0,0,0,22,0},{42,0,0,0,0,0,0,0,32,4},{110,0,0,0,60,55,0,0,0,0},{0,0,0,60,0,0,12,28,0,0},
	{0,0,0,55,0,0,0,0,0,0},{0,0,0,0,12,0,0,65,5,0},{0,0,0,0,28,0,65,0,0,0},{0,22,32,0,0,0,5,0,0,0},{0,0,4,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
	int distanceAM[12][12]={{0,5,6,20,0,0,0,0,0,0},{5,0,0,0,0,0,0,0,11,0},{6,0,0,0,0,0,0,0,13,1},{20,0,0,0,14,9,0,0,0,0},{0,0,0,14,0,0,4,12,0,0},
	{0,0,0,9,0,0,0,0,0,0},{0,0,0,0,4,0,0,7,2,0},{0,0,0,0,12,0,7,0,0,0},{0,11,13,0,0,0,2,0,0,0},{0,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
	for(i=0;i<10;i++)                                   //creating adjacency list(costs)
		for(j=0;j<10;j++)
			if(costsAM[i][j]!=0)
				costsAL[i]=newNode(i,j,costsAM[i][j]);
	for(i=0;i<10;i++)                                   //creating adjacency list(distances)
		for(j=0;j<10;j++)
			if(costsAM[i][j]!=0)
				distanceAL[i]=newNode(i,j,distanceAM[i][j]);
	/*for(i=0;i<10;i++)
	{
		ptr temp=costsAL[i];
		while(temp!=NULL)
		{
			printf("%d %d\n",temp->wt,temp->with);
			temp=temp->next;
		}
		printf("\n\n");
	}*/
	printf("Menu:\n1.Calculate minimum cost of cable conncections covering all buildings(Prim's)\n2.Calculate shortest path b/w two buildings\n3.Add two buildings\n4.Calculate minimum cost(Kruskal's)\n");
	printf("Enter your choice\n");
	scanf("%d",&chc);
	switch(chc)
	{
		case 1:	printf("Prims Algo");
			    int i=0;
				int weight=0,m;
			do
			{
				visited[i]=1;
				ptr temp=costsAL[i];
				while(temp!=NULL) //finding adjacent vertices
				{
					if(visited[temp->with]==0)
						insert(temp,i);
					temp=temp->next;
				}
				node2 current;
				while(1)
				{
					printf("The heap with edges in the following format (location 1,location 2,cost)\n");
					for(m=0;m<heapCtr;m++)
						printf("(%d,%d,%d) ",heap[m].name[1],heap[m].name[0],heap[m].wt);
					if(heapCtr==0)
						break;
					else
						current=delete();
					i=current.name[0];
					j=current.name[1];
					printf("\n");
					if(visited[i]==1)
						continue;
					else
					{
						printf("From %d to %d(%d) \n\n",j,i,current.wt);
						weight+=current.wt;
						break;
					}
				}
			}while(heapCtr!=0);
			printf("The minimum cost of cable connections covering all buildings is %d lacs",weight);
			break;
		case 2:
			printf("Enter location a\n");
			scanf("%d",&loc1);
			printf("Enter location b\n");
			scanf("%d",&loc2);
			for(i=0;i<10;i++)
				weights[i]=inf;
			weights[loc1]=0;
			int count=0;
			while(count<10)
			{
				int source=minimumIndex(weights,10),weight;
				for(i=0;i<10;i++)
					if(!(vtd(i))&&distanceAM[source][i]!=0)
					{
						weight=weights[source]+distanceAM[source][i];
						if(weight<weights[i])
							weights[i]=weight;
					}
				count++;
				visited[source]=1;
			}
			printf("The shortest distance b/w location a and location b is %d",weights[loc2]);
		case 3:
			printf("Enter the connections of 11th building (with,cost,distance)\n");
			while(no==0)
			{
				scanf("%d,%d,%d",&i,&costsAM[10][i],&distanceAM[10][i]);
				costsAM[i][10]=costsAM[10][i];
				distanceAM[i][10]=distanceAM[10][i];
				printf("Press 0 to continue entering and 1 to stop\n");
				scanf("%d",&no);
			}
			printf("Enter the connections of 12th building (with,cost,distance)\n");
			no=0;
			while(no==0)
			{
				scanf("%d,%d,%d",&i,&costsAM[11][i],&distanceAM[11][i]);
				costsAM[i][11]=costsAM[11][i];
				distanceAM[i][11]=distanceAM[11][i];
				printf("Press 0 to continue entering and 1 to stop\n");
				scanf("%d",&no);
			}
			//not updating adjacency list as it is not required in Kruskals algo
			break;
		case 4:
			weight=0;
			for(i=0;i<12;i++)    //putting edges in heap
				for(j=i;j<12;j++)
					if(costsAM[i][j]!=0)
					{
						edge.wt=costsAM[i][j];
						edge.name[0]=j;
						edge.name[1]=i;
						heap[heapCtr++]=edge;
					}
			for(i=heapCtr/2-1;i>=0;i--)//build heap
				heapify(i);
			for(i=0;i<12;i++)
				reps[i]=i;
			int edges=0;
			while(edges!=11)
			{
				node2 current;
				if(heapCtr!=0)
					current=delete();
				else 
					break;
				int repA=find(current.name[0]),repB=find(current.name[1]);
				printf("Earlier:\nRep of %d-%d\nRep of %d-%d\n",current.name[0],find(current.name[0]),current.name[1],find(current.name[1]));
				if(repA==repB)
					continue;
				else
				{
					Union(current.name[0],current.name[1]);
					printf("Later:\nRep of %d-%d\nRep of %d-%d\n",current.name[0],find(current.name[0]),current.name[1],find(current.name[1]));
					printf("a%d %d%d\n",current.wt,current.name[1],current.name[0]);
					weight+=current.wt;
					edges++;
				}
			}
			printf("Minimum cost %d lacs",weight);
			
	}
}
	