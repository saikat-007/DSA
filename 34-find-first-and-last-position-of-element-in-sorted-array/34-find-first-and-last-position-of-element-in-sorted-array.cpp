class Solution {
public:
    int firstocc(vector<int>& nums, int target)
    {
        int n=nums.size();
        int low = 0;    
        int high = n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>target)
                high=mid-1;
            
            else if(nums[mid]<target)
                low=mid+1;
            
            else
            {
                if(mid == 0 || nums[mid-1]!=target)
                    return mid;
                
                else
                    high=mid-1;
            }
        }
        
        return -1;
    }
    
    int lastocc(vector<int>& nums, int target)
    {
        int n=nums.size();
        int low = 0;    
        int high = n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>target)
                high=mid-1;
            
            else if(nums[mid]<target)
                low=mid+1;
            
            else
            {
                if(mid == n-1 || nums[mid+1]!=target)
                    return mid;
                
                else
                    low=mid+1;
            }
        }
        
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int>res;
        int f=firstocc(nums,target);
        int l=lastocc(nums,target);
        res.push_back(f);
        res.push_back(l);
        
        return res;
    }
};