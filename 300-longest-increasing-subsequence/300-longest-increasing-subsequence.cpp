class Solution {
public:
    int getLength(vector<int>& nums , int idx , int prev_idx , vector<vector<int>> &dp)
    {
        if(idx == nums.size())
            return 0;
        
        if(dp[idx][prev_idx + 1] != -1)
            return dp[idx][prev_idx + 1];
        
        int len = 0 + getLength(nums , idx + 1 , prev_idx , dp) ;
        
        if(prev_idx == -1 || nums[idx] > nums[prev_idx])
            len = max(len , 1 + getLength(nums , idx + 1 , idx , dp));
        
        return dp[idx][prev_idx + 1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>>dp(n , (vector<int>(n+1,-1)));
        return getLength(nums,0,-1,dp);
    }
};