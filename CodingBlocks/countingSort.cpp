#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n],max=-1;
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    if(arr[i]>max)
    max=arr[i];
    }
    int count[max+1]={0};
    for(int j=0;j<n;j++)
    count[arr[j]]++;

    for(int i=1;i<=max;i++)
    count[i]+=count[i-1];
    
    int output[n];
    for (int i = 0; i<n; i++)  
    {  
        output[count[arr[i]]-1] = arr[i];  
        count[arr[i]]--;  
    } 
    for(int i=0;i<n;i++)
    cout<<output[i]<<" ";
    

	return 0;
}
