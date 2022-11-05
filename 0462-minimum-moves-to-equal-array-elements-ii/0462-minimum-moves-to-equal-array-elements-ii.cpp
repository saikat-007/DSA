class Solution {
public:
    int minMoves2(vector<int>& nums)
    {
        int median = nums.size() / 2;
        sort(nums.begin() , nums.end());
        
        int moves = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            moves += abs(nums[i]-nums[median]);
        }
        
        return moves;
    }
};