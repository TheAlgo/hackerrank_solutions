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
void DFS(string st,node *r,string print)
{
	node *root=r;
	if(root->isTerminal)
	{
		cout<<print<<endl;
		//print=st;
		
	}
	hashmap::iterator it;
	
	for(it=root->h.begin();it!=root->h.end();++it)
	{
		//print+=it->first;
		DFS(st,it->second,print+it->first);
		//cout<<"1st recusion done"<<endl;
		
	}
}
		
		
	
void helper(string s)
{
	string st;
	int len=s.length();
	node *temp=root;
	for(int i=0;i<len;i++)
	{
		if(temp->h.count(s[i]))
		{
			//st+=s[i];
			temp=temp->h[s[i]];
		}
		else
	{
		cout<<"No suggestions"<<endl;
                     insert(s);
		return;
	}
	}
	DFS(s,temp,s);
	
	
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
	//cout<<"Enter the string to be ound out"<<endl;
	cin>>n;
	while(n--)
	{
	string s;
	cin>>s;
	t.helper(s);
}
	
	return 0;
}
	

	
	
	
