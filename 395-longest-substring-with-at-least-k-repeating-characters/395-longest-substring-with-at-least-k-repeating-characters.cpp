class Solution {
public:
    int longestSubstring(string s, int k)
    {
        int n = s.size();
        if(n == 0 || n < k)
            return 0;
        
        if(k <= 1)
            return n;
        
        unordered_map<char,int>count;
        for(auto c : s)
        {
            count[c]++;
        }
        
        int i = 0;
        while(count[s[i]] >= k && i < n)
            i++;
        
        if(i >= n-1) return i;
        int leftSubStr = longestSubstring(s.substr(0,i) , k);
        
        while(i < n && count[s[i]] < k)
            i++;
        
        int rightSubStr = (i < n ) ? longestSubstring(s.substr(i,n-1) , k) : 0;
        
        return max(leftSubStr , rightSubStr);
        
    }
};