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
