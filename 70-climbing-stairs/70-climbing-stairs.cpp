class Solution {
public:
    
    //this problem is similar of solving fibonacci using dp
    
    int climbStairs(int n)
    {
        int prev2 = 0 , prev1 = 1 ;
        
        for(int i = 2 ; i <= n+1 ; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};