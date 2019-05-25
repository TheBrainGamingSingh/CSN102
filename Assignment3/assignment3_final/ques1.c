#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
typedef struct data
{
	char name[20];
	int age;
	char gender;
	char number[11];
}data;
 
typedef struct node
{
    int key; //SID
	data* student;
    struct node *left;
    struct node *right;
    int height;
}node;

typedef node* ptr;
void printinfo(ptr);
int max(int a, int b)
{
	if(a>b)
		return a;
	else 
	    return b;
}

int height(ptr n)
{
    if (n == NULL)
        return -1;
    return n->height;
}

ptr newnode(int key,char name[20],int age,char gender,char number[11])
{
	//printf("Ncheck"); 
    ptr new=(ptr)malloc(sizeof(node));
    new->key=key;
	new->student=(data*)malloc(sizeof(data));
	new->student->age=age;
	new->student->gender=gender;
	strcpy(new->student->name,name);
	strcpy(new->student->number,number);
    new->left=NULL;
    new->right=NULL;
    new->height = 0;  // new node added at leaf
	//printf("Ncheck"); 
    return(new);
}

ptr rightrotate(ptr y)
{
    ptr x = y->left;
    ptr z = x->right;
 
    x->right = y;
    y->left = z;
 
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    return x;
}

ptr leftrotate(ptr y)
{
    ptr x = y->right;
    ptr z = x->left;
 
    x->left = y;
    y->right = z;
 
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    return x;
}

int balfac(ptr tree)
{
	if(tree==NULL)
		return 0;
	else
	    return height(tree->left)-height(tree->right);		
}

ptr insert(ptr node,int key,char name[20],int age,char gender,char number[11])
{
  // printf("check"); 
    if (node==NULL)
        return(newnode(key,name,age,gender,number));
    else if(key<node->key)
        node->left=insert(node->left,key,name,age,gender,number);
    else if(key>node->key)
        node->right=insert(node->right,key,name,age,gender,number);
    else // Equal keys are not allowed
        return node;
 
    //height update
    node->height=1+max(height(node->left),height(node->right));
    int bal = balfac(node);
   
	// Left Left Case
    if (bal > 1 && key < node->left->key)
        return rightrotate(node);
 
    // Right Right Case
    if (bal < -1 && key > node->right->key)
        return leftrotate(node);
 
    // Left Right Case
    if (bal > 1 && key > node->left->key)
    {
        node->left =  leftrotate(node->left);
        return rightrotate(node);
    }
    // Right Left Case
    if (bal < -1 && key < node->right->key)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
 
    return node;
}

ptr predecessor(ptr node)
{
    ptr walker = node;
    while (walker->right!=NULL)
      walker=walker->right;
  
   return walker;
}

ptr delete(ptr root, int key)
{
    if (root==NULL)
	{
		printf("Key not found\n");
        return root;
	}
	
    if (key<root->key)
        root->left = delete(root->left, key);

    else if(key>root->key)
        root->right = delete(root->right, key);
    else
    {
        //printf("Key found\n");
		if((root->left==NULL)||(root->right==NULL))
        {
          ptr del;
		  if(root->left==NULL)
			  del=root->right;
		  else
			  del=root->left;
 
            
            if(del==NULL)
            {
                del=root;
                root=NULL;
            }
            else
             *root = *del;
            free(del);
        }
        else
        {
            ptr del=predecessor(root->left);
            // Copy the inorder predecessor's data to this node
            root->key = del->key;
			*(root->student)=*(del->student);
 
            root->left = delete(root->left,del->key);
        }
    }
	
	
 
    if(root==NULL)
      return root;

    root->height=1+max(height(root->left),height(root->right));
 
    int bal=balfac(root);
 
    // Left Left Case
    if (bal>1&&balfac(root->left)>=0)
        return rightrotate(root);
 
    // Left Right Case
    if (bal>1&&balfac(root->left)<0)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
 
    // Right Right Case
    if (bal<-1&&balfac(root->right)<=0)
        return leftrotate(root);
 
    // Right Left Case
    if (bal<-1&&balfac(root->right)>0)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
 
    return root;
}	

void inOrder(ptr root)
{
    if(root!= NULL)
    {
        inOrder(root->left);
		printf("%d ",root->key);
        inOrder(root->right);
    }
}
void inOrderI(ptr root)
{
    if(root!= NULL)
    {
        inOrderI(root->left);
		printinfo(root);
        inOrderI(root->right);
    }
}

void printinfo(ptr node)
{
	 if(node!= NULL)
    {
		printf("Student ID: %d\n",node->key);
        printf("Name: %s\n",node->student->name);
		printf("Age: %d\n",node->student->age);
		printf("Gender: %c\n",node->student->gender);
		printf("Mobile Number: %s\n\n",node->student->number);
    }
}

ptr search(ptr root,int key)
{
	if(root==NULL)
	{
		printf("Key Not Found\n");
		return NULL;
	}
	else if(key==root->key)
	{
		printf("Key Found\n");
		return root;
	}
	else if(key<root->key)
		return search(root->left,key);
	else 
		return search(root->right,key);
}

ptr stdata=NULL;
 void main()
 {  
	int i=0;
	do{
      printf("Operations Available \n1 Enter data\n2 Print\n3 Delete\n4 Search\n0 Exit\n");	
      scanf("%d",&i);
   	  
	  switch(i)
	{
	  
	  case 1: printf("Enter Student ID\n");
			  int SID;
			  scanf("%d",&SID);
			  printf("Enter Name\n");
			  char name[20];
			  scanf("%s",name);
			  printf("Enter Age\n");
			  int age;
			  scanf("%d",&age);
			  printf("Enter Gender(F/M)\n");
			  char gender=getche();
			  while(!(gender=='f'||gender=='F'||gender=='m'||gender=='M'))
			  {
				  printf("Enter Valid Input\n");
				  gender=getche();
			  }
			  
			 printf("\nEnter Mobile Number\n");
			 char number[11];
			 scanf("%s",&number);
			 number[10]='\0';
			 while(strlen(number)!=10)
			 {
				printf("Enter valid input\n");
			    scanf("%s",&number);
				number[10]='\0';
			 } 
			 if(gender=='f')
				 gender='F';
			  if(gender=='m')
				 gender='M';
			 
			 stdata=insert(stdata,SID,name,age,gender,number);
			 
			  printf("\nData:");
			  inOrder(stdata);
			  printf("\n");	
			  printf("Height of Tree:%d\n",(stdata->height));		
			 break;
			 
	case 2:   if(stdata!=NULL) 
				{
					inOrderI(stdata);
					printf("Height of Tree:%d\n",(stdata->height));			  
				}	
			  else printf("No data available");
			   printf("\n");
	  	       break;
	
	case 3:   printf("Enter the key\n");
	          int key1=0;
              scanf("%d",&key1);
			  stdata=delete(stdata,key1);
			  printf("\nData:");
				if(stdata!=NULL) 
				inOrder(stdata);
				else printf("No data available");
			  printf("\n");	
			  if(stdata!=NULL)
			  printf("Height of Tree:%d\n",(stdata->height));			  
			  break;			   
	
	case 4:   printf("Enter the key\n");
	          int key2=0;
              scanf("%d",&key2);  
	          ptr find=search(stdata,key2);
			
			if(find!=NULL) 
			 {
				 int choice=0;
			  do{
				 printf("\n\nWhich detail do you want?\n1 Student ID\n2 Name\n3 Age\n4 Gender\n5 Mobile Number\n0 No, I don't want anything, go back\n");
				scanf("%d",&choice);
				
				switch(choice)
				 {
					case 1:	printf("Student ID: %d\n",find->key);
							break;
					case 2: printf("Name: %s\n",find->student->name);
							break;
					case 3:	printf("Age: %d\n",find->student->age);
							break;
					case 4:	printf("Gender: %c\n",find->student->gender);
							break;
					case 5:	printf("Mobile Number: %s\n",find->student->number); 
							break;
					case 0:	break;
				}}while(choice!=0);
			 }
			 else printf("No data available\n");
			  break;
	case 0:   break;
	} 
	
	}while(i!=0);		  
	  
}	







