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
                
                //If the subarray has even number of negative numbers, the whole subarray has positive product.
                
                if(negCount % 2 == 0)
                {
                    maxlen = max(maxlen , i - lastZero);
                }
                
                //Otherwise, we have two choices, either - remove the prefix till the first negative element in this subarray, or remove the suffix starting from the last negative element in this subarray.
                
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