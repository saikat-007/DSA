class Solution {
public:
//     void get_subset(vector<int>& nums,int idx,vector<vector<int>>&result)
//     {
//         if(idx == nums.size()-1)
//         {
//             result.push_back({});
//             result.push_back({nums[idx]});
//         }
        
//         else
//         {
//             get_subset(nums,idx+1,result);
//             int n=result.size();
//             for(int i=0;i<n;i++)
//             {
//                 vector<int>r=result[i];
//                 r.push_back(nums[idx]);
//                 result.push_back(r);
//             }
//         }
//     }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
//         if(nums.size()==0)
//             return {{}};
        
//         vector<vector<int>>res;
//         get_subset(nums,0,res);
//         return res;
        
        if(nums.empty())
            return {{}};
        
        vector<vector<int>>result={{}};
        for(int x:nums)
        {
            int n=result.size();
            for(int i=0;i<n;i++)
            {
                vector<int>r=result[i];
                r.push_back(x);
                result.push_back(r);
            }
        }
        
        return result;
    }
};

















