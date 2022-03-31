class Solution {
public:
    void generate_subset(vector<int>& nums , int idx , vector<vector<int>>& result)
    {
        int n = nums.size();
        if(idx == n-1)
        {
            result.push_back({});
            result.push_back({nums[idx]});
        }
        else
        {
            generate_subset(nums , idx+1 , result);
            int size = result.size();
            
            for(int i = 0 ; i  < size ; i++)
            {
                vector<int>ans = result[i];
                ans.push_back(nums[idx]);
                result.push_back(ans);
            }
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        if(nums.empty())
            return {{}};
        
        vector<vector<int>>result;
        generate_subset(nums , 0 , result);
        
        return result;
    }
};