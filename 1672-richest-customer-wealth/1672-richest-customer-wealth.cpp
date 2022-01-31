class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts)
    {
        vector<int>res;
        for(int i =0 ; i < accounts.size() ; i++)
        {
            int sum = 0;
            for(int j = 0; j < accounts[i].size() ; j++)
            {
                sum+=accounts[i][j];
            }
            res.push_back(sum);
        }
        
        sort(res.begin(),res.end());
        return res[res.size()-1];
    }
};