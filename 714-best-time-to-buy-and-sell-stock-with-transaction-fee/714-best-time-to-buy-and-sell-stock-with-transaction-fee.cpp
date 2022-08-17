class Solution {
public:
    int getProfit(vector<int>& prices, int idx , int canBuy , vector<vector<int>> &dp ,int &fee)
    {
        if(idx == prices.size())    
            return 0;
        
        if(dp[idx][canBuy] != -1)
            return dp[idx][canBuy];
        
        int profit = 0;
        if(canBuy)
            profit = max(-prices[idx] + getProfit(prices , idx + 1 , 0 ,dp , fee) , getProfit(prices , idx + 1 , 1 ,dp , fee));
        
        else
            profit = max(prices[idx] - fee + getProfit(prices , idx + 1 , 1 ,dp , fee) , getProfit(prices , idx + 1 , 0 ,dp , fee));
        
        return dp[idx][canBuy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee)
    {
            vector<vector<int>>dp(prices.size() , vector<int>(2,-1));
            return getProfit(prices , 0 , 1 , dp , fee);
    }
};
