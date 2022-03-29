class Solution {
public:
    int longestOnes(vector<int>& arr, int k)
    {
        int i = 0 , j = 0 , n = arr.size() , res = 0 , zerocount = 0;
        
        while(j < n)
        {
            if(arr[j] == 0)
                zerocount++;
            
            while(zerocount > k)
            {
                if(arr[i] == 0)
                    zerocount--;
                
                i++;
            }
            
            res = max(res , j - i + 1);
            j++;
        }
        
        return res;
    }
};