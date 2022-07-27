// Using o(n) space
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


// without using extra space ,  here we are trying to sell the stock every day and finding what was the minimum price so far 
//basic idea is if I am selling today and if I have bought the stock on the day when its price was minimum they I would have obtained maximum profit 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far=prices[0];
        int max_profit=0;
        
        for(int i=0;i<prices.size();i++)
        {
            min_so_far=min(min_so_far,prices[i]);
            int profit=prices[i]-min_so_far;
            max_profit=max(profit,max_profit);
        }
        return max_profit;
    }
};
