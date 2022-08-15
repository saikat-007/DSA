class Solution {
public:
    int getMaxLen(vector<int>& nums)
    {
        int firstNegative = -1;
        int lastNegative = -1;
        int negCount = 0;
        int lastZero = -1;
        
        int maxlen = 0;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == 0)
            {
                firstNegative = -1;
                lastNegative = -1;
                negCount = 0;
                lastZero = i;
            }
            
            //splitting the whole array into subarrays by zeroes since a subarray with positive product cannot contain any zero.
            
            else
            {
                if(nums[i] < 0)
                {
                    negCount ++;
                    if(firstNegative == -1)
                        firstNegative = i;
                    
                    lastNegative = i;
                }
                
                if(negCount % 2 == 0)
                {
                    maxlen = max(maxlen , i - lastZero);
                }
                
                else
                {
                    int len = max(i - firstNegative , lastNegative - (lastZero + 1));
                    maxlen = max(len , maxlen);
                }
            }
        }
        
        return maxlen;
    }
};