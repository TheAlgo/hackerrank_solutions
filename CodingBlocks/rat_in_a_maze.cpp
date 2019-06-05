
#include<iostream>
#include<cstdlib>
using namespace std;
bool solveb(char arr[][1000],int solve[][1000],int i,int j,int m,int n)
{
    if(i==m && j==n)
    {
        solve[i][j]=1;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            cout<<solve[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        exit(0);
        return true;
    }
    if(i>m || j>n)
    return false;
    if(arr[i][j]=='X')
    return false;

    solve[i][j]=1;
    //Go Right
if(j+1<=n && arr[i][j+1]!='X'){
bool pathMila = solveb(arr,solve,i,j+1,m,n);
if(pathMila==true){
return true;
}
}
/// 2. Go Down
if(i+1<=m && arr[i+1][j]!='X'){
bool pathMila = solveb(arr,solve,i+1,j,m,n);
if(pathMila==true){
return true;
}
}

    solve[i][j]=0;
  
    return false;
}
int main() {
    int m,n;
    cin>>m>>n;
    char arr[m][1000];
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin>>arr[i][j];
    int solve[m][1000]={0};
    bool ans=solveb(arr,solve,0,0,m-1,n-1);
    if(ans)
    {
        
    }
    else
    cout<<"-1"<<endl;

	return 0;
}
