class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        long long i = 1;
        long long x;
        while(i <= n)    
        {
            x=i;
            i=i*2;
        }
        
        return x == n;
    }
};