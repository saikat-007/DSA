class Solution {
public:
    void recPermute(vector<int>&nums , vector<int>&ds , vector<vector<int>>&res , int freq[])
    {
        if(ds.size() == nums.size())
        {
            res.push_back(ds);
            return;
        }
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(freq[i] == 0)
            {
                freq[i] = 1;
                ds.push_back(nums[i]);
                recPermute(nums , ds , res , freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>>res;
        vector<int>ds;
        int freq[nums.size()];
        for(int i = 0 ; i  < nums.size() ; i++)
        {
            freq[i] = 0;
        }
        recPermute(nums,ds,res,freq);
        return res;
    }
};