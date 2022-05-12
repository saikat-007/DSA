class Solution {
public:
    
    // approach 1
    
//     void getPermutation(vector<vector<int>>&res , vector<int>&ds , vector<int>&nums , vector<int>&count)
//     {
//         if(ds.size() == nums.size())
//         {
//             res.push_back(ds);
//             return;
//         }
    
//         for(int i = 0 ; i < nums.size() ; i++)
//         {
//             if(count[i] == 0)
//             {
//                 count[i] = 1;
//                 ds.push_back(nums[i]);
//                 getPermutation(res,ds,nums,count);
//                 ds.pop_back();
//                 count[i] = 0;
//             }
//         }
//     }
    
//     vector<vector<int>> permute(vector<int>& nums)
//     {
//         int n = nums.size();
//         vector<int>visited(n,0);
        
//         vector<vector<int>>res;
//         vector<int>ds;
        
//         getPermutation(res,ds,nums,visited);
//         return res;
//     }
    
    
    //approach 2 : find the permutation for the smaller subarray and append the element which was left to the beginning
    
//     vector<vector<int>> perm(vector<int>nums)
//     {
//         if(nums.size() == 0)
//             return {{}};
        
//         vector<vector<int>>ans;
//         for(int i = 0 ; i < nums.size() ; i++)
//         {
//             vector<int>nums2;
//             for(int j = 0 ; j < nums.size() ; j++)
//             {
//                 if(i!=j)
//                 {
//                     nums2.push_back(nums[j]);
//                 }
//             }
            
//             vector<vector<int>>temp = perm(nums2);
            
//             for(auto x : temp)
//             {
//                 x.push_back(nums[i]);
//                 ans.push_back(x);
//             }
//         }
        
//         return ans;
//     }
//     vector<vector<int>> permute(vector<int>& nums)
//     {
//         return perm(nums);
//     }
    
    //approach 3:
    
    vector<vector<int>>ans;
    void perm(vector<int>&nums , int i)
    {
       if(i == nums.size()) 
       {
           ans.push_back(nums);
           return;
       }
        
       for(int j = i ; j < nums.size() ; j++)
       {
           swap(nums[i],nums[j]);
           perm(nums,i+1);
           swap(nums[i],nums[j]);
       }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        perm(nums,0);
        return ans;
    }
    
};