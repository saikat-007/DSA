class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>right(n); // to store the product of all the elements on the right side of it and this also stores the final result.
        
        int left=1; // we can make a vector like right to store product of all the elements on the left side of it but insted we can maintain a variable to save space
        
        right[n-1]=1;  //no element on right
        
        for(int i=n-2 ; i >= 0 ; i--)
        {
            right[i]=right[i+1]*nums[i+1];    
        }
        
        for(int i=0;i<n;i++)
        {
            right[i] = right[i]*left;   //updating right vector for final answer
            left=left*nums[i];
        }
        
        return right;
    }
};