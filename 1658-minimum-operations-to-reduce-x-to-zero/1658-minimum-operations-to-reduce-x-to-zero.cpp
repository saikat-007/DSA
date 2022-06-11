class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int sum = 0 ;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum+=nums[i];
        }
        
        // We have to find out the maximum subarray with the Sum = (sum - x) , why maximum? because here we have to return minimum number of operations
        
        int sum2 = sum - x;
        int i = 0 , j = 0 ;
        
        if(sum2 == 0)
            return nums.size();
        
        
        int tot = 0 , maxlength = 0 ;
        for(int j = 0 ; j < nums.size() ; j++)
        {
            tot += nums[j];
            if(tot > sum2)
            {
                while(i < nums.size() && tot > sum2)
                {
                    tot -= nums[i++];
                }
            }
            
            if(tot == sum2)
                maxlength = max(maxlength , (j-i+1));
        }
        
        if(maxlength == 0)
            return -1;
        
        return nums.size() - maxlength;
    }
};