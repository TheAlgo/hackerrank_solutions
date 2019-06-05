#include<iostream>
#include<algorithm>
using namespace std;
class node
{
	public:
	int data;
	node* left;
	node* right;
	node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
node* insert(node* root, int value){
	if(root==NULL){
		node *nn = new node(value);
		return nn;
	}
	if(value>root->data){
		root->right=insert(root->right, value);
	}else if(value<root->data){
		root->left=insert(root->left, value);
	}
	return root;
}
node* build(int* arr, node* root, int n){
	for(int i=0; i<n; i++){
		root = insert(root,arr[i]);
	}
	return root;
}
void printIn(node *root)
{
	if(root==NULL)
	return;

	cout<<root->data<<" ";
	printIn(root->left);
	printIn(root->right);
}
node* deleteBST(node *root,int data)
{
	if(root==NULL)
	return NULL;
	
	else if(data<root->data)
	{
		root->left=deleteBST(root->left,data);
		return root;
	}
	else if(root->data==data)
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			return NULL;
		}
		else if(root->left!=NULL && root->right==NULL)
		{
			node *temp=root->left;
			delete root;
			return temp;
		}
		else if(root->left==NULL && root->right!=NULL)
		{
			node *temp=root->right;
			delete root;
			return temp;
		}
		node *replace =root->right;
		while(replace->left!=NULL)
		replace = replace->left;
		
		root->data=replace->data;
		root->right=deleteBST(root->right,replace->data);
		return root;
	}
	else 
	{
		root->right=deleteBST(root->right,data);
		return root;
	}
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr1[n];
		for(int i=0;i<n;i++)
		cin>>arr1[i];
		int m;
		//sort(arr1,arr1+n);
		cin>>m;
		int arr2[m];
		for(int j=0;j<m;j++)
		cin>>arr2[j];
		node *root=new node(arr1[0]);
		root=build(arr1,root,n);
		for(int i=0;i<m;i++)
		{
			root=deleteBST(root,arr2[i]);
		}
		printIn(root);
		
		
	}
	
	return 0;
}
