#include<stdio.h>
#include<stdlib.h>
//bst
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
	
} node;
typedef node* ptr; 
static int count=0;
ptr tree=NULL;
int i[2];
int ancestors[2][32];

ptr newnode(int key)
{
	ptr new=(ptr)(malloc(sizeof(node)));
	new->data=key;
	new->left=NULL;
	new->right=NULL;
	
	return new;
}

ptr insert(ptr root,int key)
{
     if(root==NULL)
	{
		//printf("Check");
		return newnode(key);
	}
	else if(key<root->data)
		root->left=insert(root->left,key);
	else if(key>root->data)
		root->right=insert(root->right,key);
    else  
		return root; // equal keys not allowed
}

ptr search(ptr tree,int key,int j)
{
	if(tree==NULL)
	{	
		return NULL;
	}
	else if(tree->data==key)
	{	
		ancestors[j][i[j]++]=tree->data;
		return tree;
	}
	else if(key>tree->data)
	{
		ancestors[j][i[j]++]=tree->data;
		return search(tree->right,key,j);
	}
	else 
	{
		ancestors[j][i[j]++]=tree->data;
		return search(tree->left,key,j);
	}
}


void inorderprint(ptr root)
{
    if(root==NULL)
		return;
	else 
	{
		inorderprint(root->left);
		printf("%d ",root->data);
		inorderprint(root->right);
	}
	return;
}

void LCA(ptr tree,int M,int N)
{
  if( search(tree,M,0) && search(tree,N,1))
  {
	printf("\nAncestors of %d are : ",M);
		for(int x=i[0]-1;x>=0;x--)
		{
			printf("%d ",ancestors[0][x]);
		}
	printf("\nAncestors of %d are : ",N);
		for(int x=i[1]-1;x>=0;x--)
		{
			printf("%d ",ancestors[1][x]);
		}
	//least common ancestor
	int lca=99999;
	
	for(int x=i[0]-1;x>=0;x--)
	{
		for(int y=i[1]-1;y>=0;y--)
			if(ancestors[0][x]==ancestors[1][y])
			{
				lca=ancestors[1][y];
				break;
			}
		if(lca!=99999)
			break;
	}
  
	printf("\nLeast common ancestor of %d and %d is %d\n",M,N,lca);
	i[0]=0;
	i[1]=0;
	
  }
  
  
  else printf("\nKeys not present\n");
}



 void main()
 {  

	  int i=0;
	  do
	  {
	  if(count==32)
	  { 
		printf("\nTree is full\n");
	  }	
  
	  
      printf("\nOperations Available \n0 Exit\n1 Enter\n2 Print\n3 LCA(M,N)\n");	
      scanf("%d",&i);
   	  
	  switch(i)
	{
	  case 0: return;
	  
	  case 1:if(count<32)
			{		  
			  printf("Enter an integer\n");
	          int key=0;
              scanf("%d",&key);
			  tree=insert(tree,key);
			  count++;// stores number of values inserted
			}  
			  break;
	  case 2:  printf("Data:");
			   if(tree)
			   inorderprint(tree);
			   else printf(" No data available");
			   printf("\n");
			   break;
	  case 3: printf("Enter M\n");
	          int key1=0;
              scanf("%d",&key1);
			  printf("Enter N\n");
	          int key2=0;
              scanf("%d",&key2);
			  LCA(tree,key1,key2);
	} 		  
	
	 }while(i!=0);	
	 
	 return;
}	  