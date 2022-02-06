class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size()<=2)
            return nums.size();
        
        int i,j=2,n=nums.size();
        for(int i=2;i<n;i++)
        {
          if(nums[i]!=nums[j-2])
          {
              nums[j]=nums[i];
              j++;
          }
        }
        
        return j;
    }
};