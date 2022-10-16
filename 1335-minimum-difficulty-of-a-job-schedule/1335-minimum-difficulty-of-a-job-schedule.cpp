// class Solution {
// public:
//     int calc(vector<int>& jobDifficulty, int d , int start , int n)
//     {
//         if(d == 1)
//         {
//             int m = INT_MIN;
            
//             for(int i = start ; i < n ; i++)
//             {
//                 m = max(m , jobDifficulty[i]);
//             }
            
//             return m;
//         }
        
//         else
//         {
//             int m = INT_MIN;
//             int res = INT_MAX;
//             for(int i = start ; i < n - d + 1 ; i++)
//             {
//                 m = max(m , jobDifficulty[i]);
//                 res = min(res , m + calc(jobDifficulty , d - 1 , i + 1 , n));
//             }
            
//             return res;
//         }
//     }
    
//     int minDifficulty(vector<int>& jobDifficulty, int d)
//     {
//         int n = jobDifficulty.size();
//         if(n < d)
//             return -1;
        
//         else
//             return calc(jobDifficulty , d , 0 , n);
//     }
// };

class Solution {
public:
    int calc(vector<int>& jobDifficulty, int d , int start , int n , vector<vector<int>> &dp)
    {
        if(d == 1)
        {
            int m = INT_MIN;
            
            for(int i = start ; i < n ; i++)
            {
                m = max(m , jobDifficulty[i]);
            }
            
            return m ;
        }
        
        if(dp[start][d] != -1)
            return dp[start][d];
        
        else
        {
            int m = INT_MIN;
            int res = INT_MAX;
            for(int i = start ; i < n - d + 1 ; i++)
            {
                m = max(m , jobDifficulty[i]);
                res = min(res , m + calc(jobDifficulty , d - 1 , i + 1 , n , dp));
            }
            
            return dp[start][d] = res;
        }
        
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        vector<vector<int>>dp(n+1 , vector<int>(d+1 , -1));
        
        if(n < d)
            return -1;
        
        else
            return calc(jobDifficulty , d , 0 , n , dp);  
    }
};