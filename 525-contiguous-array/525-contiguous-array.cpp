class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        int sum=0,maxlength=0;
        
        //changing "0" elements to -1
        
        for(int i=0;i<nums.size();i++)
        {
            nums[i]==0?nums[i]=-1:nums[i]=1;
        }
        
        //now the vector becomes a vector of -1 and 1 , and the logic is to find the largest subarray with sum = 0
        
        unordered_map<int,int>m;
        m[0]=-1;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
          
            if(m.find(sum)!=m.end())
                maxlength=max(maxlength,i-m[sum]);
                
            else
                m[sum]=i;
            
        }
        
        return maxlength;
    }
};