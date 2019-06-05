#include<iostream>
#include<map>
#include<cstring>
#define hashmap map<char,node*>
using namespace std;
class node
{
	public:
	char data;
	bool isTerminal;
	hashmap h;
	node(char d)
	{
		data=d;
		isTerminal=false;
	}
};
class trie
{
	public:
	node *root;
	trie()
	{
		root=new node(' ');;
	} 
	
void insert(string s)
{
	int len=s.length();
	node *temp=root;
	for(int i=0;i<len;i++)
	{
		char ch=s[i];
		if(temp->h.count(ch)==0)
		{
			node *child=new node(ch);
			temp->h[ch]=child;
			temp=child;
		}
		else
		temp=temp->h[ch];
	}
	temp->isTerminal=true;
}
bool search(string s)
{
	
	int len=s.length();
	node *temp=root;
	for(int i=0;i<len;i++)
	{
		char ch=s[i];
		if(temp->h.count(ch)>0)
		{
			temp=temp->h[ch];
		}
		else 
		return false;
	}
	return temp->isTerminal;
}

};	
int main()
{
	trie t;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string st;
		cin>>st;
		t.insert(st);
	}
	cout<<"Enter the string to be searched"<<endl;
	string s;
	cin>>s;
	if(t.search(s))
	cout<<"Successful"<<endl;
	
	return 0;
}
	

	
	
	
