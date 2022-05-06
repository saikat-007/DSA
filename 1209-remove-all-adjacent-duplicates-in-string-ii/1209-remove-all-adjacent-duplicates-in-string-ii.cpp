class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        vector<pair<int,int>>stk;
        string ans;
        
        for(auto x : s)
        {
            if(stk.size() == 0 || stk.back().first != x)
                stk.push_back({x,1});
            
            else 
                stk.back().second++;
            
            if(stk.back().second == k)
                stk.pop_back();
        }
        
        for(auto i : stk)
        {
            ans.append(i.second,i.first);
        }
        
        return ans;
    }
};