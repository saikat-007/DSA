class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0 , r = 0 , length = 0 , n = s.size();
        
        unordered_map<char,int>mp;
        while(r < n)
        {
            if(mp.find(s[r]) == mp.end())
                mp[s[r]] = r;
            
            else
            {
                l = max(l , mp[s[r]] + 1);
                mp[s[r]] = r;
            }
            
            length = max(length , r - l + 1);
            r++;
        }
        
        return length;
    }
};