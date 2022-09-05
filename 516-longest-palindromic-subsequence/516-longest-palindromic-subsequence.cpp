class Solution {
public:
    int get(string &s ,string & rev ,int i , int j , vector<vector<int>>&dp)
    {
        if(i < 0 || j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == rev[j])
            return dp[i][j] = 1 + get(s,rev,i-1,j-1,dp);
        
        else
            return dp[i][j] = max(get(s,rev,i-1,j ,dp) , get(s,rev,i,j-1 ,dp));
    }
    
    int longestPalindromeSubseq(string s) 
    {
        string rev = s;
        reverse(rev.begin() , rev.end());
        
        int n = s.size();
        vector<vector<int>>dp(n,(vector<int>(n,-1)));
        
        return get(s,rev,n-1,n-1,dp);
    }
};