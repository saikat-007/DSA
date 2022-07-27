class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int>max_prof(n);
        
        max_prof[n-1] = prices[n-1];
        
        for(int i = n-2 ; i >= 0 ; i--)
        {
            max_prof[i] = max(max_prof[i+1] , prices[i]);
        }
        
        int profit = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            profit = max(profit , max_prof[i] - prices[i]);
        }
        
        return profit;
    }
};