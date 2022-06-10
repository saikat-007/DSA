class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int length = 0 , l = 0 , r = 0;
        unordered_set<char>st;
        int n = s.size();
        
        while(r < n)
        {
            if(st.find(s[r]) == st.end())
                st.insert(s[r]);
            
            else
            {
                while(st.find(s[r]) != st.end())
                {
                    st.erase(s[l++]);
                }
                st.insert(s[r]);
            }
            
            length = max(length , r - l + 1);
            r++;
        }
        
        return length;
    }
};