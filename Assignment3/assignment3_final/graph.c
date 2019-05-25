#include<stdio.h>
#include<stdlib.h>
#define MSJ 9999
typedef struct adjlist_node{
	int dest;
	int distance;
	int cost;
	//char* name;
	struct adjlist_node* next;
} adjn;

typedef struct adjlist{
  adjn* head;	
} adjl;

typedef struct graph{
 int vertex;
 adjl* array;
} graph;

adjn* newnode(int dest,int cost,int distance)
{
	adjn* newn=(adjn*)malloc(sizeof(adjn));
	newn->dest=dest;
	newn->cost=cost;
	newn->distance=distance;
	
	return newn;
}

graph* newgraph(int vertex)
{
	graph* newg=(graph*)malloc(sizeof(graph));
	newg->vertex=vertex;
	
	newg->array=(adjl*)malloc(vertex*sizeof(adjl));
	
	for(int i=0;i<vertex;i++)
		newg->array[i].head=NULL;
	
	return newg;
}

void newedge(graph* gr,int src,int dest,int cost,int distance)
{
	adjn* node=newnode(dest,cost,distance);
	node->next=gr->array[src].head;
	gr->array[src].head=node;
	
	node=newnode(src,cost,distance);
	node->next=gr->array[dest].head;
	gr->array[dest].head=node;
}
char* name[12]={"NAB","IT","CSE","Admin","Civil","SPIC","Library","Meta","CC","ECE"};
void printgraph(graph* gr)
{
	for(int i=0;i<gr->vertex;i++)
	{
		adjn* walker=gr->array[i].head;
		printf("Building #%d: %s",i+1,name[i]);
		while(walker)
		{
		 printf("->%s",name[walker->dest]);
		 walker=walker->next;
		}
		printf("\n");
	}
}
int left(int i)
{
	return 2*i + 1;
}
int right(int i)
{
	return 2*i + 2;
}

int min(int a,int b)
{
	return a<b ? a : b;
}

typedef struct heap_node{
	int vertex;
	int key;
} heapn;

typedef struct Heap{
	int count;
	int size;
	int *position;
	heapn** array;
	
}heap;

heapn* newheapnode(int vertex,int key)
{
	heapn* new=(heapn*)malloc(sizeof(heapn));
	new->vertex=vertex;
	new->key=key;
	
	return new;
}

heap* newheap(int size)
{
	heap* newh=(heap*)malloc(sizeof(heap));
	newh->position=(int*)malloc(size*sizeof(int));
	newh->count=0;
	newh->size=size;
	newh->array=(heapn**)malloc(size*sizeof(heapn*));
	return newh;
}
 
void swap(heapn** x,heapn** y)
{
	heapn* z=*x;
	*x=*y;
	*y=z;
}

void heapify(heap* tree,int i)
{
	int m=i;
	int l=left(i);
	int r=right(i);
	
	if(l<tree->count && tree->array[l]->key < tree->array[m]->key)
		m=l;
	if(r<tree->count && tree->array[r]->key < tree->array[m]->key)
		m=r;
	
	if(m!=i)
	{
		heapn* mnode=tree->array[m];
		heapn* inode=tree->array[i];
		
		tree->position[mnode->vertex]=i;
		tree->position[inode->vertex]=m;
		
		swap(&tree->array[m],&tree->array[i]);
		
		heapify(tree,m);
	}
}

int isempty(heap* tree)
{
	return (tree->count==0);
}

heapn* deletemin(heap* tree)
{
	if(isempty(tree))
		return NULL;
	heapn* root=tree->array[0];
	heapn* last=tree->array[tree->count-1];
	tree->array[0]=last;
	
	tree->position[root->vertex]=tree->count-1;
	tree->position[last->vertex]=0;
	
	(tree->count)--;
	
	heapify(tree,0);
	
	return root;
}

void decreasekey(heap* tree,int vertex,int key)
{
	int i=tree->position[vertex];
	tree->array[i]->key=key;
	
	while(i && tree->array[i]->key < tree->array[(i-1)/2]->key)
	{
		tree->position[tree->array[i]->vertex]=(i-1)/2;
		tree->position[tree->array[(i-1)/2]->vertex]=i;
		
		swap(&tree->array[i],&tree->array[(i-1)/2]);
		
		i=(i-1/2);
	}
}

int ispresent(heap* tree,int vertex)
{
	return (tree->position[vertex] < tree->count);
}

void printheap(heap* tree)
{
	int i=0;
	while(i < tree->count)
	{
		printf("#%d: %s ,",tree->array[i]->vertex,name[tree->array[i]->vertex]);
		i++;
	}
	printf("\n");
}
void prims(graph* grph)
{
	int v=grph->vertex;
	int parent[v];
	int key[v];
	
	heap* vertices=newheap(v);
	
	for(int n=1;n<v;n++)
	{
		parent[n]=-1;
		key[n]=MSJ;
		vertices->array[n]=newheapnode(n,key[n]);
		vertices->position[n]=n;
	}
	
	key[0]=0;
	vertices->array[0]=newheapnode(0,key[0]);
	vertices->position[0]=0;
	
	vertices->count=v;
	
	while(!isempty(vertices))
	{
		heapn* minimum=deletemin(vertices);
		int m=minimum->vertex;
		printf("%s\n",name[m]);
		printheap(vertices);
		
		adjn* walker=grph->array[m].head;
		
		while(walker)
		{
			int x = walker->dest;
			
			if(ispresent(vertices,x) && walker->cost < key[m])
			{
				key[m]=walker->cost;
				parent[x]=m;
				decreasekey(vertices,x,key[x]);
			}
			walker=walker->next;
		}
		
	}

	int totalcost=0;
	for(int w=0;w<v;w++)
		totalcost+=key[w];
	for(int w=1;w<v;w++)
		printf("%s-%s(Cost is %d lacs)\n",name[parent[w]],name[w],key[w]);
	
	printf("\n\nTotal Cost is %d lacs\n",totalcost);
	
}

void main()
{
	
	graph* buildings=newgraph(10);
	//char* name[9]={"NAB","IT","CSE","Admin","Civil","SPIC","Library","Meta","CC","ECE"};
	newedge(buildings,0,1,13,5);
	newedge(buildings,0,2,42,6);
	newedge(buildings,0,3,110,20);
	newedge(buildings,4,3,60,14);
	newedge(buildings,3,5,55,9);
	newedge(buildings,6,4,12,4);
	newedge(buildings,6,7,65,7);
	newedge(buildings,6,8,5,2);
	newedge(buildings,4,7,28,12);
	newedge(buildings,2,8,32,13);
	newedge(buildings,1,8,22,11);
	newedge(buildings,2,9,4,1);

	printgraph(buildings);
	prims(buildings);
}

