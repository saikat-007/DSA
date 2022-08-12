
//Recursive Solution
// class Solution {
// public:
//     int getCost(vector<int>& cost , int idx , int n)
//     {
//         if(idx >= n)
//             return 0;
        
//         else
//             return cost[idx] + min(getCost(cost , idx+1 , n) , getCost(cost , idx + 2 , n));
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) 
//     {
//         int n = cost.size();
//         return min(getCost(cost,0,n) , getCost(cost,1,n));
//     }
// };

// class Solution {
// public
//     int getCost(vector<int>& cost , int idx , int n , vector<int>& dp)
//     {
//         if(idx >= n)
//             return 0;
        
//         if(dp[idx] != -1)
//             return dp[idx];
        
//         else
//             return dp[idx] = cost[idx] + min(getCost(cost , idx+1 , n , dp) , getCost(cost , idx + 2 , n , dp));
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) 
//     {
//         int n = cost.size();
//         vector<int>dp(n,-1);
//         return min(getCost(cost,0,n,dp) , getCost(cost,1,n,dp));
//     }
// };

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int>dp(n,-1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i = 2 ; i < n ; i++)
        {
            int onestep = dp[i-1];
            int twostep = dp[i-2];
            
            dp[i] = min(onestep , twostep) + cost[i];
        }
        
        return min(dp[n-1] , dp[n-2]);
    }
};