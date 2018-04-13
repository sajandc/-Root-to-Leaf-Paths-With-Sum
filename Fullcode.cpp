#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *newnode(int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}
struct node *insert(struct node *root, int data)
{
	if(root==NULL)
		return newnode(data);
	if(data <= root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
	
}

 
void check(int arr[],int len,int num)
{
	int s=0;
	for(int i=0;i<len;i++)
	{
		s=s+arr[i];
	}
	if(s==num)
	{
		for(int i=0;i<len;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}
}
void path(struct node *root,int arr[],int len,int num)
{
	if(root==NULL)
		return;
	arr[len]=root->data;
	len++;
	if(root->left==NULL && root->right==NULL)
		check(arr,len,num);
	else
	{
		path(root->left,arr,len,num);
		path(root->right,arr,len,num);
	}
}
void arr(struct node* node,int num) 
{
  int p[1000];
  path(node, p, 0,num);
}
void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}


int main()
{
	int i,a,b,n,d;
	struct node *root=NULL,*temp=NULL;
	printf("enter the no of nodes ");
	scanf("%d",&n);
	scanf("%d",&d);
	root=insert(root,d);
	for(i=1;i<n;i++)
	{
		scanf("%d",&d);
		insert(root,d);
	}
	inorder(root);
	int num,p=0;
	cin>>num;
	arr(root,num);
}

