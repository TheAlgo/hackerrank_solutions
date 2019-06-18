class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size();
        if(n==0 || n==1)
            return n;
        int count=1;
        int j=0;
        arr[j]=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[j])
            {
                arr[++j]=arr[i];
                count++;
            }
            else 
                continue;
        }
        return count;
        
    }
};
