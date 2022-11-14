class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        map<int,int>mp;
        int n = nums.size();
        long long maxSum = 0 , sum = 0;
        
        for(int i = 0 ; i < k-1 ; i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
        }
        
        for(int i = k-1 ; i < n ; i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
            
            if(mp.size() == k)
            {
                maxSum = max(maxSum , sum);
            }
            
            if(mp[nums[i-k+1]] == 1)
            {
                mp.erase(nums[i-k+1]);
            }
            
            else
            {
                mp[nums[i-k+1]]--;
            }
            
            sum -= nums[i-k+1];
        }
        
        return maxSum;
    }
};