class Solution {
public:
    int numberOfbits(int n)
    {
        return log2(n) + 1;
    }
    
    int concatenatedBinary(int n)
    {
        long long ans = 0 ;
        int MOD = 1e9 + 7;
        
        for(int i = 1 ; i <= n ; i++)    
        {
            ans = ((ans << numberOfbits(i)) + i ) % MOD;
        }
        
        return ans;
    }
};