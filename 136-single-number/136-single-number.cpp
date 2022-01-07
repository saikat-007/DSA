class Solution {
public:
    int singleNumber(vector<int>& n) {
        // sort(nums.begin(),nums.end());
        // int res=0;
        // int i=0;
        // for(i=0;i<nums.size()-1;i+=2)
        // {
        //     if(nums[i]!=nums[i+1])
        //          break;
        // }
        // return nums[i];
        
        //We can use bitwise XOR operator to get desired output in a more optimised way as XOR with same number cancels out so the only single number will leave behind.
        
        int num=n[0];
        for(int i=1;i<n.size();i++)
        {
            num^=n[i];
        }
        return  num;
    }
};