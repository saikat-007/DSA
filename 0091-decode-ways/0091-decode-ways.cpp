class Solution {
public:
    int getWays(string s , int i , vector<int>&dp)
    {
        if(s[i] == '0')
            return 0;
        
        if(i >= s.size() - 1)
            return 1;
        
        int one = 0;
        int two = 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        if(s[i] != '0')
            one =  getWays(s , i+1 , dp);
        
        if(((s[i] == '2' && s[i+1] <= '6') || (s[i] == '1' && s[i+1] <= '9')) && i < s.size())
            two = getWays(s , i+2 , dp);
        
        return dp[i] = one + two;
    }
    
    int numDecodings(string s)
    {
        vector<int>dp(s.size() + 1 , -1);
        return getWays(s , 0 , dp);
    }
};