class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int sum = 0;
        int leftsum=0;
        bool flag=false;
        int n =nums.size();
        int res;
        
        if(n == 1)
            return n;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        for(int i=0;i<n;i++)
        {
            sum=sum-nums[i];
            if(sum == leftsum)
            {
                res=i;
                flag = true;
                break;
            }
            leftsum+=nums[i];
        }
        if(flag == false)
            res= -1;
        
        return res;
    }
};