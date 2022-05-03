class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int>cnums;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            cnums.push_back(nums[i]);
        }
        
        sort(cnums.begin() , cnums.end());
        
        int start = nums.size() , end = 0;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] != cnums[i])
            {
                start = min(start , i);
                end = max(end , i);
            }
        }
        
        return (end - start) > 0 ? (end - start + 1) : 0;
    }
};