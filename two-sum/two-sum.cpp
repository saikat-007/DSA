class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
//         int low=0,high=nums.size()-1;
        
//         vector<int>res;
        
//         sort(nums.begin(),nums.end());
        
//         while(low<high)
//         {
//             if(nums[low]+nums[high] == target)
//             {
//                  res.push_back(low);
//                  res.push_back(high);
//                  break;
                 
//             }
            
//             else if(nums[low]+nums[high] > target)
//             {
//                 high--;
//             }
            
//             else
//             {
//                 low++;
//             }
//         }
//         return res;
        
        vector<int>ans;
        bool f=false;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((target-nums[i])==nums[j]){
                    ans.push_back(i);
                    ans.push_back(j);
                    f=true;
                }
            }
            if(f==true)
                break;
        }
        return ans;
    }
};