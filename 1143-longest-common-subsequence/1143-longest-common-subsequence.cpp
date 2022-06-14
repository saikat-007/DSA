class Solution {
public:
//     int f(string &t1 , string &t2 , int i ,int j)
//     {
//         if(i < 0 || j < 0)
//             return 0;
        
//         if(t1[i] == t2[j])
//             return 1 + f(t1,t2,i-1,j-1);
        
//         return max(f(t1,t2,i-1,j),f(t1,t2,i,j-1));
//     }
    
    
//     int longestCommonSubsequence(string text1, string text2)
//     {
//         int m = text1.size();
//         int n = text2.size();
        
//         vector<vector<int>>dp(m,vector<int>(n,-1));
        
//         return f(text1,text2,m-1,n-1);
//     }
    
    
    
    
//     int f(string &t1 , string &t2 , int i ,int j,vector<vector<int>>dp)
//     {
//         if(i < 0 || j < 0)
//             return 0;
        
//         if(dp[i][j]!= -1)
//             return dp[i][j];
            
//         if(t1[i] == t2[j])
//             return dp[i][j] = 1 + f(t1,t2,i-1,j-1,dp);
        
//         return dp[i][j] = max(f(t1,t2,i-1,j,dp),f(t1,t2,i,j-1,dp));
//     }
    
//     int longestCommonSubsequence(string text1, string text2)
//     {
//         int m = text1.size();
//         int n = text2.size();
        
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return f(text1,text2,m-1,n-1,dp);
//     }
    
    
    
    
     int dp[1000 + 1][1000 + 1];
    
    int maxLen(string& s1, string& s2, int n, int m)
    {
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
               if (i == 0 || j == 0) {
                   dp[i][j] = 0;
               } 
            }
        }
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(0 + dp[i][j - 1], 0 + dp[i - 1][j]);
            }
        }

        return dp[n][m];
    }
        
    int longestCommonSubsequence(string s1, string s2) 
    {
        memset(dp, -1, sizeof(dp));        
        return maxLen(s1, s2, s1.length(), s2.length());
    }
};