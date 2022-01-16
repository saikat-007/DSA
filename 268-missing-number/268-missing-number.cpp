class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=nums.size();
        vector<bool>res(n+1,false);
        for(int i=0;i<n;i++)
        {
            res[nums[i]]=true;
        }
        
        int ans;
        
        for(int i=0;i<=n;i++)
        {
            if(res[i] == false)
                ans = i;
        }
        return ans;
    }
};

//approach : direct address table