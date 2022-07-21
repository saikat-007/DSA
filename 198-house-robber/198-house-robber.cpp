class Solution {
public:
    int getMax(vector<int>& nums,int idx,vector<int>&dp)
    {
        if(idx == 0)
            return nums[idx];
        
        if(idx < 0)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int take = nums[idx] + getMax(nums,idx-2,dp);
        int not_take = getMax(nums,idx-1,dp);
        
        return dp[idx] = max(take,not_take);
    }
    
    int rob(vector<int>& nums)
    {
        int n = nums.size()-1;
        vector<int>dp(n+1,-1);
        return getMax(nums,n,dp);
    }
};