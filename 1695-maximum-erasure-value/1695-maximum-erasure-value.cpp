class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        unordered_set<int>mp;
        int n = nums.size();
        int maxsum = 0;
        int sum = 0;
        int i = 0;
        for(int j = 0 ; j < n ; j++)
        {
            while(mp.find(nums[j]) != mp.end())
            {
                mp.erase(nums[i]);                    
                sum-=nums[i++];
            }
            
            mp.insert(nums[j]);
            sum+=nums[j];
            maxsum = max(maxsum , sum);
        }
        
        return maxsum;
    }
};