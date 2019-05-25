//heap
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
	
} node;
typedef node* ptr; 

ptr newnode(int key)
{
	ptr new=(ptr)(malloc(sizeof(node)));
	new->data=key;
	new->left=NULL;
	new->right=NULL;
	
	return new;
}

ptr insert(ptr root, int key)
{
	if(root==NULL)
	{
	 return newnode(key);
	}
	else if(key<root->data)
	{
	 if(root->left==NULL)	
	 root->left=insert(root->left,key);
	 else
	 root->right=insert(root->right,key);
	}
    else  
	return root; // equal keys not allowed
}
ptr tree=NULL;

void main()
{
 tree=insert(tree,5)
}