class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target)
    {
        vector<int>res;
        int n = num.size();
        int low = 0 , high = n - 1;
        
        while(low <= high)
        {
            if(num[low] + num[high] == target)
            {
                res.push_back(low+1);
                res.push_back(high+1);
                break;
            }
            
            else if(num[low] + num[high] < target)
                low++;
            
            else
                high--;
        }
        
        return res;
    }
};