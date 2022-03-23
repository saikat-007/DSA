class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>>result;
        unordered_map<string,vector<string>>mp;
        
        for(auto s : strs)
        {
            string tmp = s;
            sort(s.begin() , s.end());
            mp[s].push_back(tmp);
        }
        
        for(auto x : mp)
        {
            vector<string>helper = x.second;
            result.push_back(helper);
        }
        
        return result;
    }
};