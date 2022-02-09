class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        int count=0;
        while(i<nums.size() && j<nums.size())
        {
            if(nums[j]-nums[i] == k)
            {
                count++;
                i++;
                j++;
                
                while(j<nums.size() && nums[j]==nums[j-1])
                {
                    j++;
                }
                
            }
            
        
            else if(j-i == 0 || nums[j]-nums[i] > k)
            {
                i++;
                
                if(j-i == 0)
                    j++;
            }
            
            else
                j++;
        }
        
        return count;
    }
};