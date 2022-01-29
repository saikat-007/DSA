class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        
        vector<int>res;
        res.push_back(sum);
        for(int i=nums.size()-2;i>=0;i--)
        {
            res.push_back(sum-nums[i+1]);
            sum=sum-nums[i+1];
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};