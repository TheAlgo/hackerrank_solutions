class Solution {
public:
    int util(vector<int> arr,int i,int j,int key)
    {
        if(i>j)
            return -1;
        int mid=(i+j)/2;
        
        if(arr[mid]==key)
            return mid;
        
        if(arr[i]<=arr[mid])
        {
            if(arr[i]<=key && key<=arr[mid])
                return util(arr,i,mid-1,key);
            else
               return util(arr,mid+1,j,key);
        }
        if(key>=arr[mid] && key<=arr[j])
            return util(arr,mid+1,j,key);
        
        return util(arr,i,mid-1,key);
    }
    int search(vector<int>& arr, int target) {
       return util(arr,0,arr.size()-1,target);
    }
};
