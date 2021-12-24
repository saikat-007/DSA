class Solution {
public:
    int maxSubArray(vector<int>& n) {
        int max_sum=INT_MIN;
        int curr_sum=0;
        
        for(int i=0;i<n.size();i++)
        {
            curr_sum += n[i];
            if(curr_sum > max_sum)
                    max_sum=curr_sum;
            
            if(curr_sum<0)
                    curr_sum=0;
            
        }
        return max_sum;
    }
};