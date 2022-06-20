class Solution {
public:
    int solveRec(int i , int j , vector<vector<int>>& grid, int m , int n , vector<vector<int>> &dp)
    {
        if(i == m-1 && j == n-1)
            return grid[m-1][n-1];
        
        if(i > m-1 || j > n-1)
            return INT_MAX;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        else
            return dp[i][j] = min(solveRec(i+1,j,grid,m,n,dp) , solveRec(i,j+1,grid,m,n,dp)) + grid[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return solveRec(0,0,grid,m,n,dp);
    }
};