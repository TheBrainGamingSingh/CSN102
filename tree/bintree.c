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
int preindex=0;

int PRE[32]; 
int IN[32];
int count[2];
ptr tree=NULL;
ptr newnode(int key)
{
	ptr new=(ptr)(malloc(sizeof(node)));
	new->data=key;
	new->left=NULL;
	new->right=NULL;
	
	return new;
}

void postOrder(ptr root)
{
    if(root!= NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
		printf("%d ",root->data);
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
	 
	 root->left=buildtree(in,pre,start,inindex-1);
	 root->right=buildtree(in,pre,inindex+1,end); //similar to binary search
	 return root;
}


void main()
{

  int len = sizeof(in)/sizeof(in[0]);
  tree=buildtree(in,pre,0,len - 1);
	
  postOrder(tree);
}