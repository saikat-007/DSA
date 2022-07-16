class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int sum = 0;
        if(nums.size() == 1)
            return 0;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum+=nums[i];
        }
        
        int leftsum = 0;
        bool flag = false;
        int res;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum-=nums[i];
            if(sum == leftsum)
            {
                res = i;
                flag = true;
                break;
            }
            leftsum+=nums[i];
        }
        
        if(flag == false)
            return -1;
        
        return res;
    }
};