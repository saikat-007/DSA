class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int>temp(n);
        
        if(n == 0 || k <= 0)
            return;
        
        for(int i = 0 ; i < n ; i++)
        {   
            temp[i] = nums[i];
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            nums[(i+k)%n] = temp[i];
        }
    }
};