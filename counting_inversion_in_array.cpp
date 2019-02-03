#include<iostream>
using namespace std;
int merge(int *arr,int *LArr,int* RArr,int m,int n)
{
    int i=0,j=0,k=0;
    int count = 0;
    while(i<m && j<n)
    {
        if(LArr[i]<=RArr[j])
            arr[k++] = LArr[i++];
        else
        {
             arr[k++] = RArr[j++];
             count = count + m - i;
        }
    }
    while(i<m)
         arr[k++] = LArr[i++];
    while(j<n)
         arr[k++] = RArr[j++];
    return count;
}
int mergeSort(int *arr,int start,int end)
{
    if(start>end)
        return 0;
    if(start==end)
        return 0;
    if(start==end-1)
    {
        if(arr[start]<=arr[end])
            return 0;
        else
            swap(arr[start],arr[end]);
        return 1;
    }

    int mid = (start+end)/2;
    int *LArr = new int[mid+1];
    int *RArr = new int[end-mid];
    int i;
    for(i=start;i<=mid;i++)
        LArr[i] = arr[i];
    for(i=mid+1;i<=end;i++)
        RArr[i-(mid+1)] = arr[i];


    int count = 0;
    count += mergeSort(LArr,0,mid);
    count += mergeSort(RArr,0,end-mid-1);
    count += merge(arr,LArr,RArr,mid+1,end-mid);

    delete [] LArr;
    delete [] RArr;
    return count;
}

int  main()
{
    int t,n,*arr;
    cin>>t;
    while(t--)
    {
        cin>>n;
        arr = new int[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<mergeSort(arr,0,n-1)<<endl;
    }


}
