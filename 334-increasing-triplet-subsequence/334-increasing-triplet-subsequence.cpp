class Solution {
public:
    bool increasingTriplet(vector<int>& n)
    {
        int low = INT_MAX;
        int mid = INT_MAX;
        
        for(int i=0 ; i<n.size() ; i++)
        {
            if(n[i] <= low)
                low = n[i];
            
            else if(n[i] >= low && n[i] <= mid)
                mid = n[i];
            
            else if(n[i] > mid)
                return true;
        }
        
        return false;
    }
};