class Solution {
public:
//     bool checkPal(string s)
//     {
//         int low = 0,high = s.size()-1;
//         while(high > low)
//         {
//             if(s[low++] != s[high--])
//             {
//                 return false;
//             }
            
//         }
//         return true;
//     }
    
//     int countSubstrings(string s)
//     {
//         vector<string>res;
//         int count = 0;
//         for(int i = 0 ; i < s.size() ; i++)    
//         {
//             for(int j = i ; j < s.size() ; j++)
//             {
//                 string temp = s.substr(i,j-i+1);
//                 if(checkPal(temp) == true)
//                    count++;    
//             }
//         }
        
//         return count;
//     }
    
    int countSubstrings(string s)
    {
        if(s.length() == 0)return 0;
        int n = s.length();
        int dp[n][n];
        int res = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            dp[i][i] = true;
            res++;
        }
        
        for(int i = 0 ; i < n-1 ; i++)
        {
            dp[i][i+1] = (s[i] == s[i+1]);
            if(dp[i][i+1])
                res++;
        }
        
        for(int len = 3 ; len <= n ; len++)
        {
            for(int i = 0 , j = i+len-1 ; j < n ;i++,j++)
            {
                dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                if(dp[i][j]) res++;
            }
        }
        
        return res;
        
    }
};