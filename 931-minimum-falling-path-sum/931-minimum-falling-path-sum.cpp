// class Solution {
// public:
//     int getSum(vector<vector<int>>& matrix , int row ,int col)
//     {
//         if(col < 0 || col >= matrix.size())
//             return 1e6;
        
//         if(row == matrix.size()-1)
//             return matrix[row][col];
        
//         int below = matrix[row][col] + getSum(matrix , row + 1 , col);
//         int digLeft = matrix[row][col] + getSum(matrix , row + 1 , col - 1);
//         int digRight = matrix[row][col] + getSum(matrix , row + 1 , col + 1);
        
//         int sum = min(below , min(digLeft , digRight));
        
//         return sum;
//     }
    
//     int minFallingPathSum(vector<vector<int>>& matrix)
//     {
//         int sum = INT_MAX;
//         for(int col = 0 ; col < matrix.size() ; col++)    
//         {
//             sum = min(sum , getSum(matrix,0,col));
//         }
        
//         return sum;
//     }
// };


class Solution {
public:
    int getSum(vector<vector<int>>& matrix , int row ,int col ,vector<vector<int>> &dp)
    {
        if(col < 0 || col >= matrix.size())
            return 1e6;
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        if(row == matrix.size()-1)
            return matrix[row][col];
        
        int below = matrix[row][col] + getSum(matrix , row + 1 , col , dp);
        int digLeft = matrix[row][col] + getSum(matrix , row + 1 , col - 1 , dp);
        int digRight = matrix[row][col] + getSum(matrix , row + 1 , col + 1 , dp);
        
        int sum = min(below , min(digLeft , digRight));
        dp[row][col] = sum;
        return sum;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int sum = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int col = 0 ; col < matrix.size() ; col++)    
        {
            sum = min(sum , getSum(matrix,0,col,dp));
        }
        
        return sum;
    }
};