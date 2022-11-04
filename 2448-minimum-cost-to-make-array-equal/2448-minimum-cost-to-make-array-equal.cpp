class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost)
    {
        // Sort nums and cost according to value of nums    
        
        long long n = nums.size();
        vector<pair<int,int>>v;
        for(int i = 0 ; i < n ; i++)
        {
            v.push_back({nums[i],cost[i]});
        }
        
        sort(v.begin() , v.end());
        
        long long sum = 0;
        long long tot = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            sum += v[i].second;
        }
        
        long long i = 0;
        long long median = 0;
        
        while(tot < (sum + 1)/2 && i < n)
        {
            tot += v[i].second;
            median = v[i].first;
            i++;
        }
        
        long long ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            ans += abs(median - nums[i]) * cost[i];
        }
        
        return ans;
    }
};