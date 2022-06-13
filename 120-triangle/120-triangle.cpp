class Solution {
public:
    
//     int minsum = INT_MAX;
    
//     void getTotal(int i , int j ,vector<vector<int>>& triangle , int sum)
//     {
//         if(i == triangle.size())
//         {
//             minsum = min(sum , minsum);
//             return;
//         }
        
//         sum += triangle[i][j];
//         getTotal(i+1 , j , triangle , sum);
//         getTotal(i+1 , j+1 , triangle , sum);
//     }
    
   
//     int minimumTotal(vector<vector<int>>& triangle)
//     {
//         int sum = 0 , i = 0 , j = 0;
//         getTotal(i,j,triangle,sum);
        
//         return minsum;
//     }
    
    
       int solve(int i, int j, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp) {
		if(i == n - 1)
			return triangle[i][j];
		if(dp[i][j] != -1)
			return dp[i][j];
		int bottom = triangle[i][j] + solve(i+1, j, n, triangle, dp);
		int  bottom_right = triangle[i][j] + solve(i+1, j+1, n, triangle, dp);
		return dp[i][j] = min(bottom, bottom_right);
	    }
    
	    int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>>dp(n, vector<int>(n, -1));
		return solve(0, 0, n, triangle, dp);
	}
};