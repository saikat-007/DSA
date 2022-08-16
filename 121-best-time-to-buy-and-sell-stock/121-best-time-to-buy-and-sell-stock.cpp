class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int>max_profit_after_current_day(n);
        
        max_profit_after_current_day[n-1] = prices[n-1];
        
        for(int i = n-2 ; i >= 0 ; i--)
        {
            max_profit_after_current_day[i] =  max(max_profit_after_current_day[i+1] , prices[i]);
        }
        
        int maxProf = INT_MIN;
        for(int i = 0 ; i < n ; i++)
        {
            maxProf = max(maxProf , max_profit_after_current_day[i] - prices[i]);
        }
        
        return maxProf;
    }
};