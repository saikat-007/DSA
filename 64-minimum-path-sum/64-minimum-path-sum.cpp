class Solution {
public:
    int getsum(int i , int j , vector<vector<int>>& grid , int m , int n , vector<vector<int>> &dp)
    {
        if(i == m-1 && j == n-1)
            return grid[i][j];
        
        if(i > m-1 ||  j > n-1)
            return INT_MAX;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = grid[i][j] + min(getsum(i+1,j,grid,m,n,dp),getsum(i,j+1,grid,m,n,dp));
    }
    
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return getsum(0,0,grid,m,n,dp);
    }
};