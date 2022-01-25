class Solution {
public:
    bool validMountainArray(vector<int>& arr)
    {
        int n = arr.size()-1;
        int low=0,high=n;
        
        if(arr.size() < 3)
            return false;
        
        while(low+1 < n && arr[low]<arr[low+1])
            low++;
        
        while(high-1 > 0 && arr[high] < arr[high-1])
            high--;
        
        return (low == high);
    }
};