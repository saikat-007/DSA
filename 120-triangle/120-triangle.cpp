class Solution {
public:
    int getTotal(int idx , int row , vector<vector<int>>& triangle , vector<vector<int>>& dp)
    {
        if(row == triangle.size() - 1)
            return triangle[row][idx];
        
        if(dp[row][idx] != -1)
            return dp[row][idx];
        
        else
            return dp[row][idx] = triangle[row][idx] + min(getTotal(idx , row + 1 , triangle , dp) , getTotal(idx + 1, row + 1 , triangle , dp));
    }
    
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int idx = 0 , row = 0;
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return getTotal(idx,row,triangle,dp);
    }
};