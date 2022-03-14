class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        stack<int>stk;
        int n = nums.size();
        vector<int>res(n);
        
        for(int i = (2*n)-1 ; i >= 0 ; i--)
        {
            while(stk.empty() == false && stk.top() <= nums[i%n])
                stk.pop();               // to maintain increasing order
            
            if(i < n)
            {
            int nxt_greater = (stk.empty())?-1:stk.top();
            res[i]=(nxt_greater);
            
            }
            stk.push(nums[i%n]);
        }
        
        return res;
    }
};