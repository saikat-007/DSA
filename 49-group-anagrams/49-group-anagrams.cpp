class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>m;
        
        for(auto s : strs)
        {
            string temp = s;
            sort(s.begin() , s.end());
            m[s].push_back(temp);
        }
        
        for(auto x : m)
        {
            res.push_back(x.second);
        }
        
        return res;
    }
};