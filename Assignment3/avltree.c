//avl tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
}node;

int max(int a, int b)
{
	if(a>b)
		return a;
	else 
	    return b;
}

typedef node* nptr;

int getheight(nptr tree)
{
    if (tree == NULL)
        return -1;
    return tree->height;
}


nptr newnode(int key)
{
    nptr new = (nptr)malloc(sizeof(struct node));
    new->key   = key;
    new->left   = NULL;
    new->right  = NULL;
    new->height = 0;  // new node is initially added at leaf
    return (new);
}

nptr rotateright(nptr tree)
{
	
	nptr x=tree->left;
	nptr y=x->right;
	
	tree->left=y;
	x->right=tree;
	
	tree->height=1+ max(getheight(tree->left),getheight(tree->right));
    x->height=1+ max(getheight(x->left),getheight(x->right));
	
	return x;
}

nptr rotateleft(nptr tree)
{
	
	nptr x=tree->right;
	nptr y=x->left;
	
	tree->right=y;
	x->left=tree;
	
	tree->height=1+ max(getheight(tree->left),getheight(tree->right));
    x->height=1+ max(getheight(x->left),getheight(x->right));
	
	return x;
}

int balfac(nptr tree)
{
	if(tree==NULL)
		return 0;
	else
	    return getheight(tree->left)-getheight(tree->right);		
}

nptr insert(nptr node, int key)
{
     //the normal BST insertion 
    if (node == NULL)
        return(newnode(key));
 
    if (key < node->key)
        node->left  = insert(node->left,key);
    else if (key > node->key)
        node->right = insert(node->right,key);
    else // Equal keys are not allowed in BST
        return node;
		
	 node->height = 1 + max(getheight(node->left),getheight(node->right));	
	 
	 int bal = balfac(node);
	
	// Left Left Case 
	if (bal > 1 && key < node->left->key)
        return rotateright(node);
 
    // Right Right Case
    if (bal < -1 && key > node->right->key)
        return rotateleft(node);
 
    // Left Right Case
    if (bal > 1 && key > node->left->key)
    {
        node->left =  rotateleft(node->left);
        return rotateright(node);
    }
 
    // Right Left Case
    if (bal < -1 && key < node->right->key)
    {
        node->right = rotateright(node->right);
        return rotateleft(node);
    }
 
    return node;
}

void inOrder(nptr tree)
{
    if(tree!= NULL)
    {
        inOrder(tree->left);
		printf("%d ", tree->key);
        inOrder(tree->right);
    }
}


nptr avltree=NULL;


 void main()
 {  

	  int i=0;
	  
	
	do{
      printf("Operations Available \n1 Enter data\n2 Print data\n0 Exit\n");	
      scanf("%d",&i);
   	  
	  switch(i)
	{
	  
	  case 1: printf("Enter an integer\n");
	          int key=0;
              scanf("%d",&key);
			  avltree=insert(avltree,key);
			 // printf("Check");
			  
			 
	  case 2:  printf("Data:");
			   inOrder(avltree);
			   printf("\n");
			   printf("Height of Tree:%d\n",(avltree->height));
	  	       break;
	   
	  case 0: return;
	} 
	}while(i!=0);		  
	  
}	