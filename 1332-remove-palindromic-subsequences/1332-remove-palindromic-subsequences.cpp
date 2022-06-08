class Solution {
public:
    bool isPal(string &s)
    {
        int low = 0 , high = s.size() - 1;
        
        while(low <= high)
        {
            if(s[low++] != s[high--])
                return false;
        }
        
        return true;
    }
    
    int removePalindromeSub(string s)
    {
        if(isPal(s))        
            return 1;
        
        else
            return 2;
    }
};