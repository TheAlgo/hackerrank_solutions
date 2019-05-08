//Anticlockwise spiral matrix
#include<iostream>
using namespace std;
int main() {
    int m,n;
	cin>>m>>n;
	int arr[m][n];
    int i,k=0,l=0;
	for(i=0;i<m;i++)
	for(int j=0;j<n;j++)
	cin>>arr[i][j];
int count=0;
    while(k<m && l<n)
    {
        //first column
        for(i=k;i<m;i++)
        {
            if(count!=0)
            cout<<" ";
        cout<<arr[i][l]<<",";
        count++;
        }
        l++;
        

        //last row
        for(i=l;i<n;i++)
        cout<<" "<<arr[m-1][i]<<",";
        m--;

        //last column
        for(i=m-1;i>=k;i--)
        cout<<" "<<arr[i][n-1]<<",";
        n--;
//first row
        for(i=n-1;i>k;i--)
        cout<<" "<<arr[k][i]<<",";
        k++;
    }

cout<<" END"<<endl;
	return 0;
}
