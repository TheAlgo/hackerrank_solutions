#include<iostream>
#include<queue>
using namespace std;
class node
{
	public:
	node* left;
	node* right;
	int data;
	int level;
	
	node(int d)
	{
		level=0;
		data=d;
		left=NULL;
		right=NULL;
	}
	
};

void inorder(node* root)
	{
		if(root==NULL)
		return;
		
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
node* insert()
{
		node* root = new node(1);
		queue<node*> q;
		q.push(root);
		while(!q.empty())
		{
			node* n=q.front();
			q.pop();
			int a,b;
			cin>>a>>b;
			if(a!=-1)
			{
				n->left=new node(a);
				q.push(n->left);
			}
			if(b!=-1)
			{
				n->right=new node(b);
				q.push(n->right);
			}
			
		}
		return root;
}
void swapnodes(node* &root,int k)
{
	queue<node*> q;
	root->level=0;
	q.push(root);
	while(!q.empty())
	{
		node* n=q.front();
		q.pop();
		int currlevel=n->level+1;
		if(currlevel%k==0)
		{
			node* temp =(n->left);
			n->left=n->right;
			(n->right)=temp;
		}
		//else if(currlevel%k==0
		if(n->left!=NULL)
		{
		(n->left)->level=currlevel;
		q.push(n->left);
	}
	if(n->right!=NULL)
	{
		(n->right)->level=currlevel;
		
		q.push(n->right);
	}
}
}
int main()
{
	int n;
	cin>>n;
	node *root=NULL;
	root=insert();
	int k;
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
	cin>>k;
	swapnodes(root,k);
	inorder(root);
	cout<<endl;
}
	return 0;
}
