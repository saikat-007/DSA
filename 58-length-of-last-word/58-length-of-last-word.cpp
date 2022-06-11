class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int r = s.size() - 1 , len = 0;
        while(r >= 0 && s[r] == ' ')
        {
            r--;
        }
        
        while(r >= 0 && s[r] != ' ')
        {
            len++;
            r--;
        }
        
        return len;
    }
};