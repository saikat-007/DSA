class Solution {
public:
    void com_sum(int idx,int target,vector<int>&arr,vector<vector<int>>&res,vector<int>&container)
    {
        if(idx == arr.size())
        {
            if(target == 0)
                res.push_back(container);
            
            return;
        }
        
        if(arr[idx] <= target)
        {
            container.push_back(arr[idx]);
            com_sum(idx,target-arr[idx],arr,res,container);
            container.pop_back();
        }
                                   
        com_sum(idx+1,target,arr,res,container);
    }
   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>>res;
        vector<int>container;
        com_sum(0,target,candidates,res,container);
        return res;
    }
};