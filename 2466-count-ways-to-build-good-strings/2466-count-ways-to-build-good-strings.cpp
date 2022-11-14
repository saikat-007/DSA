// class Solution {
// public:
//     int getcount(int length , int zero , int one , int n)
//     {
//         int count = 0;
        
//         if(length == n)
//             return 1;
        
//         if(length > n)
//             return 0;
        
//         else
//             return getcount(length + one , zero , one , n) + getcount(length + zero , zero ,one , n);
//     }
    
//     int countGoodStrings(int low, int high, int zero, int one)
//     {
//         int ans = 0;
//         vector<int>dp(high,-1);
        
//         for(int i = low ; i <= high ; i++)
//         {
//             ans += getcount(0 , zero , one , i);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int mod = 1e9 + 7;
//     int getcount(vector<int>&dp , int zero , int one , int n)
//     {
//         if(n == 0) return 1;
//         if(n < 0) return 0;
        
//         if(dp[n] != -1) return dp[n];
        
//         return dp[n] = (getcount(dp,zero,one,n-zero) % mod + getcount(dp,zero,one,n-one) % mod) % mod;
//     }
    
//     int countGoodStrings(int low, int high, int zero, int one)
//     {
//         int ans = 0;
//         vector<int>dp(high+1,-1);
        
//         for(int i = low ; i <= high ; i++)
//         {
//             ans = (ans + getcount(dp , zero , one , i) % mod) % mod;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int>dp(high+1 , 0);
        dp[0] = 1;
        for(int k = 1 ; k <= high ; k++)
        {
            if(k >= zero) dp[k] += dp[k-zero] % mod;
            if(k >= one) dp[k] += dp[k-one] % mod;
        }
        
        long long count = 0;
        for(int i = low ; i <= high ; i++)
        {
            count = (count + dp[i]) % mod;
        }
        
        return count;
    }
};






















