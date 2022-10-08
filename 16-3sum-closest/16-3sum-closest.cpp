class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int i,j,k,min_diff = INT_MAX,sum = 0;
        
        for(int i = 0 ; i < nums.size() - 2 ; i++)
        {
            int j = i+1;
            int k = nums.size()-1;
            
            while(j < k)
            {
                int diff = abs(target - nums[i] - nums[j] - nums[k]);
                
                if(diff < min_diff)
                {
                    min_diff = diff;
                    sum = nums[i]+nums[j]+nums[k];
                }
                
                else if(nums[i]+nums[j]+nums[k] > target)
                    k--;
                
                else if(nums[i]+nums[j]+nums[k] < target)
                    j++;
                
                else
                    return sum;
            }
        }
        
        return sum;
    }
};