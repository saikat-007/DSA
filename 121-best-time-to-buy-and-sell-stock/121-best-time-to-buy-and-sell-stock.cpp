class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int min_buying_price = INT_MAX;
        int maxProf = 0;
        
        for(int i = 0 ; i < prices.size() ; i++)
        {
            min_buying_price = min(min_buying_price,prices[i]);
            maxProf = max(maxProf , prices[i] - min_buying_price );
        }
        
        return maxProf;
    }
};