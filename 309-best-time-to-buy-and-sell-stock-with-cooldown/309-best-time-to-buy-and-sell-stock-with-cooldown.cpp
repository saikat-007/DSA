// class Solution {
// public:
//     int getProfit(vector<int>& prices, int idx , int canBuy , vector<vector<int>> &dp)
//     {
//         if(idx >= prices.size())    
//             return 0;
        
//         if(dp[idx][canBuy] != -1)
//             return dp[idx][canBuy];
        
//         int profit = 0;
//         if(canBuy)
//             profit = max(-prices[idx] + getProfit(prices , idx + 1 , 0 ,dp) , getProfit(prices , idx + 1 , 1 ,dp));
        
//         else if(idx != prices.size() - 2)
//             profit = max(prices[idx] + getProfit(prices , idx + 2 , 1 ,dp) , getProfit(prices , idx + 1 , 0 ,dp));
        
//         return dp[idx][canBuy] = profit;
//     }
    
//     int maxProfit(vector<int>& prices)
//     {
//         vector<vector<int>>dp(prices.size() , vector<int>(2,-1));
//         return getProfit(prices , 0 , 1 , dp);
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>>dp(prices.size()+2 , vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int idx = n-1 ; idx >= 0 ;idx--)
        {
            for(int canBuy = 0 ; canBuy <= 1 ; canBuy++)
            {
                int profit = 0;
                if(canBuy)
                    profit = max(-prices[idx] + dp[idx+1][0] , dp[idx+1][1]);

                else
                    profit = max(prices[idx] + dp[idx+2][1] , dp[idx+1][0]);

                dp[idx][canBuy] = profit;
            }
        }
        
        return dp[0][1];
    }  
};
