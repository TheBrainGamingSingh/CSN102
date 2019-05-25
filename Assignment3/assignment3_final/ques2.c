#include<stdio.h>
#include<stdlib.h>
#define M 99999
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
	
} node;
typedef node* ptr; 
int error;
int preindex=0;
ptr tree=NULL;
ptr newnode(int key)
{
	ptr new=(ptr)(malloc(sizeof(node)));
	new->data=key;
	new->left=NULL;
	new->right=NULL;
	
	return new;
}

int PRE[50],IN[50];
int count;
void postOrder(ptr root)
{
    if(root!= NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
		printf("%d ",root->data);
    }
}

void inOrder(ptr root)
{
    if(root!= NULL)
    {
        inOrder(root->left);
		printf("%d ",root->data);
        inOrder(root->right);
    }
}

void preOrder(ptr root)
{
    if(root!= NULL)
    {
        printf("%d ",root->data);
		preOrder(root->left);
        preOrder(root->right);
    }
}

int search(int inorder[],int starti,int endi,int key)
{
 for(int i=starti;i<=endi;i++)
	 if(inorder[i]==key)
		 return i;
	 
 return M;	 
}

ptr buildtree(int in[],int pre[],int start,int end)
{
	if(start>end)
		return NULL;
	
	 ptr root=newnode(pre[preindex++]); //if node is empty, allocate a key
 
	if(start==end) //tree/subtree is complete
		return root;
		
	 int inindex = search(in,start,end,root->data);	
	 if(inindex==M)
	 {
		 printf("\nEnter Valid Traversals\n");
		 error=M;
		 return NULL;
	 }
	 root->left=buildtree(in,pre,start,inindex-1);
	 root->right=buildtree(in,pre,inindex+1,end); //similar to binary search
	 return root;
}


void main()
{
 int a=0;
 do{
  count=0;
  tree=NULL;
  preindex=0; 
	 
  if(error==M)
  {
	  printf("\nThis time, enter a valid tree traversal\n");
	  error=0;
  }	  

  if(count>50)
  {
	  printf("Please enter a value less than that, else my program wont work!\n");
	  continue;
  }
  printf("Enter In-Order Traversal of the tree\n"); 
		char temp;
		do{
			scanf("%d%c",&IN[count++],&temp);
		}while(temp!='\n');
  
  printf("Enter Pre-Order Traversal of the tree\n"); 
		int k=0;
		do{
			scanf("%d%c",&PRE[k++],&temp);
		}while(temp!='\n');
	
  if(k!=count)
	error=M;
  tree=buildtree(IN,PRE,0,count- 1);
	
  if(error==M)
   continue;  
  printf("\nIn-Order is   :  ");
  inOrder(tree);
  printf("\nPre-Order is  :  ");
  preOrder(tree);
  printf("\nPost-Order is :  ");
  postOrder(tree);
  

  while(1)
  { 
    printf("\n\nPress 1 if you want to enter another traversals else Press 0 \n 0 Exit\n 1 Construct another tree\n");
    scanf("%d",&a);
    if(a==0)
	  return;
    else if(a==1)
		break;
	else printf("Enter Valid Input");
  }
  
 }while(1); 
}

