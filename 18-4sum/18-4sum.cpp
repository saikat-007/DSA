class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {   
        vector<vector<int>>res;
        if(nums.size() == 0)
            return res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                
                int target2 = target - nums[i] - nums[j];
                int low=j+1;
                int high=nums.size()-1;
                
                while(low < high)
                {
                    
                    if(nums[low] + nums[high] < target2)
                        low++;
                    
                    else if(nums[low] + nums[high] > target2)
                        high--;
                    
                    else
                    {
                        vector<int> res_vec(4,0);
                        res_vec[0]=(nums[i]);
                        res_vec[1]=(nums[j]);
                        res_vec[2]=(nums[low]);
                        res_vec[3]=(nums[high]);
                        
                        res.push_back(res_vec);
                        
                        //ignoring duplicates for 3rd and 4th item
                        
                        while(low<high && nums[low] == res_vec[2])
                            low++;
                        
                        while(low<high && nums[high] == res_vec[3])
                            high--;
                        
                    }
                }
                
                //ignoring duplicates for 2nd item
                
                while(j+1 < nums.size() && nums[j] == nums[j+1])
                    j++;
            }
            
            while(i+1 < nums.size() && nums[i] == nums[i+1])
                i++;
        }
        
        return res;
    }
};