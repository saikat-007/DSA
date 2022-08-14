class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int product_so_far = 1;
        int maxProduct = INT_MIN;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            product_so_far *= nums[i];
            maxProduct = max(maxProduct , product_so_far);
            
            // for cases like [-2,3,-4]
            
            if(product_so_far == 0)
                product_so_far = 1;
        }
        
        //checking backwards fo cases like [3,-1,4]
        
        product_so_far = 1;
        
        for(int i = nums.size() - 1 ; i >= 0 ; i--)
        {
            product_so_far *= nums[i];
            maxProduct = max(maxProduct , product_so_far);
            
            if(product_so_far == 0)
                product_so_far = 1;
        }
        
        return maxProduct;
    }
};