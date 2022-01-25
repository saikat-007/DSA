class Solution {
public:
    int maxSubArray(vector<int>& n) {
        int max_sum=INT_MIN;
        int curr_sum=0;
        
       for(int i=0;i<n.size();i++)
       {
           if(curr_sum < 0)
               curr_sum=0;
           
           curr_sum+=n[i];
           max_sum=max(max_sum,curr_sum);
       }
     return max_sum;
    }
};