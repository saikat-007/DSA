// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
    {
        int low = 1 , high = n , res;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(!isBadVersion(mid))
                low = mid+1;
            
            else
            {
                if(!isBadVersion(mid-1))
                {
                    res = mid;
                    break;
                }
                
                else
                    high = mid-1;
            }
                
        }
        
        return res;
    }
};