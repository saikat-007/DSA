class Solution {
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char,int>mp;
        for(int i = 0 ; i < s.size() ;i++)
        {
            mp[s[i]]++;
        }
        
        int count = 0;
        bool odd_found = false;
        for(auto it : mp)
        {
            if(it.second % 2 == 0)
                count += it.second;
            
            else
            {
                odd_found = true;
                count += (it.second - 1);
            }
                
        }
        
        if(odd_found)
            count += 1;
        
        return count;
    }
};