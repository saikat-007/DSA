//<-------------------------- Recursive ------------------------------->

// class Solution {
// public:
//     int numTrees(int n)
//     {
//         if(n == 0 || n == 1)    
//             return 1;
        
//         int count = 0;
        
//         for(int i = 1 ; i <= n ; i++)
//         {
//             count += (numTrees(i-1)*numTrees(n-i));
//         }
        
//         return count;
//     }
// };

class Solution {
public:
    int getCount(int n , vector<int>&dp)
    {
        if(n == 0 || n == 1)    
            return dp[n] = 1;
        
        int count = 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        for(int i = 1 ; i <= n ; i++)
        {
            count += (getCount(i-1 , dp)*getCount(n-i , dp));
        }
        
        return dp[n] = count;
    }
    
    int numTrees(int n)
    {
        vector<int>dp(n+1,-1);
        return getCount(n , dp);
    }
};