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
void insert(node*& head,int data)
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
 
 node *reverse (node *head, int k)  
{  
    node* current = head;  
    node* next = NULL;  
    node* prev = NULL;  
    int count = 0;  
  
      

    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
      
    
    if (next != NULL)  
    head->next = reverse(next, k);  
  

    return prev;  
}  

 int main()
 {
	 node* head=NULL;
	 int n,k;
	 cin>>n>>k;
	 for(int i=0;i<n;i++)
	 {
		 int a;
		 cin>>a;
		 insert(head,a);
	}
	
	
	head=reverse(head,k);

	print(head);
	return 0;
}
