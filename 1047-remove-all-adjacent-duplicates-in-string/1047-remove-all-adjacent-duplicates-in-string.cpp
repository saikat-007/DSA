class Solution {
public:
    string removeDuplicates(string s)
    {
        string ans = "";
        for(auto x : s)
        {
            if(ans.size() != 0 && ans.back() == x)
                ans.pop_back();
            
            else
                ans.push_back(x);
        }
        
        return ans;
    }
};