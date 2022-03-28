class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int>res(size);
        int low = 0;
        int high = size-1;
        
        for(int i = size-1 ; i >=0 ; i--)
        {
            if(abs(nums[low]) > abs(nums[high]))
            {
                res[i] = nums[low] * nums[low];
                low++;
            }
            
            else
            {
                res[i] = nums[high] * nums[high];
                high -- ;
            }
        }
        
        return res;
    }
};