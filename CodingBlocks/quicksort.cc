#include<iostream>
#include<cstdlib>
using namespace std;
void shuffle(int *arr,int s,int e)
{
	srand(time(NULL));
	int i,j;
	for(i=e;i>0;i--)
	{
		j=rand()%(i+1);
		swap(arr[i],arr[j]);
	}
}
int partition(int *arr,int s,int e)
{
	int i=s-1;
	int p=e;
	int j=s;
	for(j=s;j<e;j++)
	{
		if(arr[j]<arr[p])
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[p]);
	return i+1;
}
void quicksort(int *arr,int s,int e)
{
	if(s>=e)
	return;
	int p=partition(arr,s,e);
	quicksort(arr,s,p-1);
	quicksort(arr,p+1,e);
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	shuffle(arr,0,n-1);
	quicksort(arr,0,n-1);
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	return 0;
}
