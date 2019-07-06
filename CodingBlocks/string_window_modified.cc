#include<bits/stdc++.h>
using namespace std;
string smallestWindow(string st1,string st2)
{
   vector<int> map(128,0);
    for(auto c:st2) map[c]++;
    int head=0,end=0,d=INT_MAX,begin=0;
    int counter=st2.size();
    int len=st1.size();
    while(end<len)
    {
       if(map[st1[end++]]-->0) counter--;
        while(counter==0)
        {
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[st1[begin++]]++==0) counter++;  //make it invalid
            }  
        }
    }
    if(d==INT_MAX)
    return "No string";
    else
    return st1.substr(head,d);
}
int main() {
    string st1,st2;
    getline(cin,st1);
    getline(cin,st2);
   // cin>>st1>>st2;
    cout<<smallestWindow(st1,st2)<<endl;
	return 0;
}
