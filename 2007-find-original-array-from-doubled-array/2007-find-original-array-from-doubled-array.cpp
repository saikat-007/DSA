class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>mp;
        vector<int>ans;
        for(auto i : changed)
        {
            mp[i]++;
        }
        
        for(auto i : mp)
        {
            int x = i.first;
            
            if(mp[x] == 0)
                continue;
            
            while(mp[x] > 0)
            {
                ans.push_back(x);
                mp[x]--;
                mp[2*x]--;
            }
            
            if(mp[x] < 0)
                return {};
        }
        
        return ans;
    }
};