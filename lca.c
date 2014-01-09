#include<stdio.h>

struct Node
	{
	int data;
	struct Node *left,*right;
	};
struct Node *root=NULL;
struct Node *insert(struct Node *ptr,int n)
	{
	struct Node *new=malloc(sizeof (struct Node));
	new->data=n;
	if(ptr==NULL)
		return new;
	else if(ptr->data>n)
		ptr->left= insert(ptr->left,n);
	else if(ptr->data<n)
                ptr->right=insert(ptr->right,n);
	return ptr;
	}
void *search(struct Node *ptr,int n)
	{
	if(ptr==NULL)
		return (void*)0;
	else 
		{
		if(ptr->data==n)
			return (void*)1;
		else if(ptr->data>n)
			return(search(ptr->left,n));
		else if(ptr->data<n)
                        return(search(ptr->right,n));

		}
	}
void inorder(struct Node *ptr)
	{
	if(ptr!=NULL)
		{
		inorder(ptr->left);
		printf("%d ",ptr->data);
		inorder(ptr->right);
		}
	}

void lca(int a,int b,struct Node *ptr)
	{
	pthread_t ls,rs;
	
	}


int main()
	{
	int i,n;
	for(i=0;i<5;i++)
		{
		scanf("%d",&n);
		root=insert(root,n);
		}

	inorder(root);		
	
	printf("%d\n",search(root,5));
	return 0;
	}
