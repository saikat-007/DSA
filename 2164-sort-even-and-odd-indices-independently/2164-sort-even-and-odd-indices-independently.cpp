class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums)
    {
        vector<int>odd_idx;
        vector<int>even_idx;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                even_idx.push_back(nums[i]);
            }
            else
            {
                odd_idx.push_back(nums[i]);
            }
        }
        
        sort(odd_idx.begin(),odd_idx.end(),greater<int>());
        sort(even_idx.begin(),even_idx.end());
        
        int k=0,j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2 == 0)
            {
                nums[i]=even_idx[j];
                j++;
            }
            else
            {
                nums[i]=odd_idx[k];
                k++;
            }
        }
        
        return nums;
    }
};