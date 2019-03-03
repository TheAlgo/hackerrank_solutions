#include <string>
#include <ios>
#include <iostream>
#include "algorithm"
#include<bits/stdc++.h>

using namespace std;

void swap(char *a, char *b)
{
    char* temp;
    temp = a;
    a = b;
    b = temp;
}



void permute(string str, int l, int r)
{
    
    if(l==r)
    cout << str << " ";
    else
    {
        for (int i = l; i < r; i++) {
            swap(str[l],str[i]);
            sort(str.begin()+l+1,str.end()); // to maintain order
            permute(str,l+1,r);
            swap(str[l],str[i]);
            
        }
    }
    
    
    
}



int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int testcase;
    scanf("%d",&testcase);

    while(testcase--)
    {
        int size;
        string str;
        cin >> str;
        
        sort(str.begin(),str.end()); // lexicographically smallest comes first
        size = str.size();
        permute(str,0,size);
        cout << endl;

    }
    
    // fclose(stdout);

    return 0;
}
