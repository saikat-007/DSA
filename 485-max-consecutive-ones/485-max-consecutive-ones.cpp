class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int max_one = 0;
        int curr_one = 0;
        
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == 1)
                curr_one++;
            
            max_one = max(max_one , curr_one);
            
            if(nums[i] == 0)
                curr_one = 0;
        }
        
        return max_one;
    }
};