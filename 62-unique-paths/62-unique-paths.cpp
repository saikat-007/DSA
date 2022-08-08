class Solution {
public:
    int calcPaths(int m , int n ,int i ,int j,vector<vector<int>>&dp)
    {
        if(i == m-1 && j == n-1)    
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = (i + 1 != m) ? calcPaths(m,n,i+1,j,dp) : 0;
        int right = (j + 1 != n) ? calcPaths(m,n,i,j+1,dp) : 0;
        
        return dp[i][j] = down + right;    
    }
    
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m+1 , vector<int>(n+1,-1));
        
        return calcPaths(m,n,0,0,dp);
    }
};