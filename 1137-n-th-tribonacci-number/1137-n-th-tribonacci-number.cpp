class Solution {
public:
    int get(int n,vector<int>&dp)
    {
        if(n == 0 )
            return 0;
        
        if(n == 1 || n == 2)    
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        else
            return dp[n] = get(n-1,dp) + get(n-2,dp) + get(n-3,dp);
    }
    
    int tribonacci(int n)
    {
        vector<int>dp(n+1,-1);
        return get(n,dp);
    }
};