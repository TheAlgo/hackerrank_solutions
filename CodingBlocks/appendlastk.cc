#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    
    //Constructor
    node(int d){
        data = d;
        next = NULL;
    }
};
node* insertFront(node*& head,node *ab)
{
	if(ab==NULL)
	{
		//head=new node(ab->data);
		return head;
	}
	
	node *n = new node(ab->data);
	n->next=insertFront(head,ab->next);
	head=n;
	return head;
}
void insertLast(node*& head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node *tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	tail->next=new node(data);
	return;
}


void print(node *head)
{while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
 }
 int main()
{
	int n,a,k;
	cin>>n;
	node *head=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		insertLast(head,a);
	}
	cin>>k;
	k=k%n;
	node *ab=head;
	for(int i=1;i<=n-k;i++)
	ab=ab->next;
	
	head=insertFront(head,ab);
	
	int j=1;
	while(j<=n)
	{
		cout<<head->data<<" ";
		head=head->next;
		j++;
	}
	
	return 0;
}
		

 
 
