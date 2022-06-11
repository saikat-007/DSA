class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int minlen = INT_MAX ;
        int i = 0 , j = 0 ;
        
        int n = nums.size();
        int tot = 0;
        
        for(j = 0 ; j < n ; j++)
        {
            tot += nums[j];
            while(i < n && tot >= target)
                {
                    minlen = min(minlen , (j - i + 1));
                    tot-=nums[i++];
                }
        }
        
        if(minlen == INT_MAX)
            return 0;
        
        else 
            return minlen;
    }
};