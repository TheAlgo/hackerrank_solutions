#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Biotonic(int *a,int n){
    int max_len=1;;
    int i=0;
    while(i<n-1){
        int len=1;
        while(i<n-1 && a[i+1]>=a[i]){
            i++;
            len++;
        }
        while(i<n-1 && a[i]>a[i+1]){
            i++;
            len++;
        }
        max_len=max(max_len,len);
    }
    return max_len;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<Biotonic(a,n)<<endl;
    }
}
