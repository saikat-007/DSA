class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        int st , end ;
        st = 0;
        end = nums.size()-1;
        int count = 0;
        
        sort(nums.begin(),nums.end());
        while(st < end)
        {
            if(nums[st]+nums[end] < k)
                st++;
            
            else if(nums[st]+nums[end] > k)
                end--;
            
            else
            {
                count++;
                st++;
                end--;
            }
        }
        
        return count;
    }
};