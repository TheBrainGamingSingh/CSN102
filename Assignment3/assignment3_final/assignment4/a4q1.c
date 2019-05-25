#include<stdio.h>
#include<stdlib.h>
#define MSJ 9999
char* name[12]={"NAB","IT","CSE","Admin","Civil","SPIC","Library","Meta","CC","ECE"};
typedef struct adjlistnode{//node
	int dest;//with
	int cost;//wt
	struct adjlistnode* next;
}node;

typedef struct edge{//node2
	int cost;//wt
	int vertices[2];//name
}edge;

typedef node* nptr;//ptr

nptr costadjlist[12];
nptr distanceadjlist[12];

edge heap[100];
int count_heap;
int V;
int visit[10],weights[10],representatives[12];


int find(int a)
{
	int i=representatives[a];
	while(representatives[i]!=i)
		i=representatives[i];
	
	return i;
	
}

void dounion(int a,int b)
{
	int repa=find(a),repb=find(b),counta=0,countb=0;
	for(int i=0;i<12;i++)
		if(find(i)==repa)
			counta++;
		else if(find(i)==repb)
			countb++;
		
	if(counta>countb)
			representatives[find(b)]=find(a);
	else
			representatives[find(a)]=find(b);
}

int checkvisit(int i)
{
	if(visit[i]==0)
		return 0;
	else 
		return 1;
}

int leastindex(int arr[],int size)
{
	int least;
	for(int i=0;i<size;i++)
	if(!checkvisit(i))
	{
		least=i;
		break;
	}
	
	for(int i=0;i<size;i++)
		if(checkvisit(i)==0 && arr[i]<arr[least])
			least=i;
		
	return least;	
}

void heapify(int i)
{
	edge temp;
	int left=2*i+1;
	int right=2*i+2;
	if(i>=count_heap || left>=count_heap && right>=count_heap)
		return;
	else 
	{
		int leftchild=(heap[left]).cost;
		int rightchild=(heap[right]).cost;
		int parent=(heap[i]).cost;
		
		if(right>=count_heap)
			rightchild=parent;
		if(left>=count_heap);
			leftchild=parent;
			
		if(leftchild!=0 && leftchild < parent && leftchild < rightchild)
		{
			temp=heap[i];
			heap[i]=heap[left];
			heap[left]=temp;
		}
	
		else if(rightchild!=0 && rightchild < parent && rightchild < leftchild)
		{
			temp=heap[i];
			heap[i]=heap[right];
			heap[right]=temp;
		}
	heapify(left);
	heapify(right);
	}
}

nptr newnode(int src,int dest,int cost)
{
	nptr newn=(nptr)malloc(sizeof(node));
	newn->dest=dest;
	newn->cost=cost;
	newn->next=costadjlist[src];
	
	return newn;
}

void insert(nptr new,int src)
{
	edge temp;
	temp.cost=new->cost;
	temp.vertices[1]=src;
	temp.vertices[0]=new->dest;
	heap[count_heap++]=temp;
	
	int p=count_heap/2-1;
	if(count_heap==1) //for root node
		p=0;
	
	while(p>0)
	{
		heapify(p);
		p=(p-1)/2;
	}
	
	heapify(0);
}

edge deletemin()
{
	edge temp=heap[0];
	heap[0]=heap[--count_heap];
	heapify(0);
	
	return temp;
}

void main()
{
	int costmatrix[12][12]={{0,13,42,110,0,0,0,0,0,0},
						 {13,0,0,0,0,0,0,0,22,0},
						 {42,0,0,0,0,0,0,0,32,4},
						 {110,0,0,0,60,55,0,0,0,0},
						 {0,0,0,60,0,0,12,28,0,0},
						 {0,0,0,55,0,0,0,0,0,0},
						 {0,0,0,0,12,0,0,65,5,0},
						 {0,0,0,0,28,0,65,0,0,0},
						 {0,22,32,0,0,0,5,0,0,0},
						 {0,0,4,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0}};
	
	int distancematrix[12][12]={{0,5,6,20,0,0,0,0,0,0},
								{5,0,0,0,0,0,0,0,11,0},
								{6,0,0,0,0,0,0,0,13,1},
								{20,0,0,0,14,9,0,0,0,0},
								{0,0,0,14,0,0,4,12,0,0},
								{0,0,0,9,0,0,0,0,0,0},
								{0,0,0,0,4,0,0,7,2,0},
								{0,0,0,0,12,0,7,0,0,0},
								{0,11,13,0,0,0,2,0,0,0},
								{0,0,1,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0}};
								

	for(int i=0;i<10;i++)                                   //creating adjacency list(costs)
		for(int j=0;j<10;j++)
			if(costmatrix[i][j]!=0)
				costadjlist[i]=newnode(i,j,costmatrix[i][j]);
	for(int i=0;i<10;i++)                                   //creating adjacency list(distances)
		for(int j=0;j<10;j++)
			if(distancematrix[i][j]!=0)
				distanceadjlist[i]=newnode(i,j,distancematrix[i][j]);	


int manpreet;
do{printf("Operations Available\n0 Exit\n1 Calculate minimum cost of cable conncections covering all buildings using Prim's algorithm\n2 Calculate shortest path between two buildings\n3 Add two buildings to the graph\n4 Calculate minimum cost of connections by using Kruskal's algorithm\n");

scanf("%d",&manpreet);

switch(manpreet)
{
	case 0: break;
	
	case 1: printf("Prim's MST\n");
			/*for(int i=0;i<10;i++)
				printf("%d %s\n",i,name[i]);*/
			int i=0,j;
			int totalcost=0;
			//scanf("%d",&s);
			do{
				visit[i]=1;
				nptr temp=costadjlist[i];
				
				while(temp)
				{
					if(visit[temp->dest]==0)
						insert(temp,i);
					temp=temp->next;
				}
				
				edge minimum;
				while(1)
				{
					printf("\nContents of heap are Vertex1-Vertex2(Cost): ");
					
					for(int s=0;s<count_heap;s++)
						printf("%s-%s(%d) ",name[heap[s].vertices[1]],name[heap[s].vertices[0]],heap[s].cost);
					
					printf("\n\n");
					
					if(count_heap==0)
						break;
					
					else
						minimum=deletemin();
					  i=minimum.vertices[0];
					  j=minimum.vertices[1];
					
					if(visit[i]==1)
						continue;
					else
					{
						printf("Egde added: %s-%s(%d)\n",name[j],name[i],minimum.cost);
						totalcost+=minimum.cost;
						printf("%d\n",totalcost);
						break;
					}
				
				}
				
			}while(count_heap!=0);
			
			printf("Minimum cost of connections is %d lacs\n",totalcost);
			break;
}

}while(manpreet!=0)	;		
			
}
	

