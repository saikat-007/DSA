class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i , int j , int &m , vector<vector<int>>& dp)
    {
        if(i >= matrix.size() || j >= matrix[0].size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = solve(matrix , i , j+1 , m ,dp);
        int down = solve(matrix , i+1 , j , m , dp);
        int dia = solve(matrix , i+1 , j+1 , m , dp);
        
        if(matrix[i][j] == '1')
        {
            int ans = 1 + min(right , min(down , dia));
            m = max(m,ans);
            return dp[i][j] = ans;
        }
        
        else
            return dp[i][j] = 0;
    }
    
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int  m = 0;
        vector<vector<int>>dp(matrix.size() , vector<int>(matrix[0].size() , -1));
        solve(matrix,0,0,m,dp);
        return m*m;
    }
};