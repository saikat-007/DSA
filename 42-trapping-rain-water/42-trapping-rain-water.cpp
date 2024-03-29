// class Solution {
// public:
//     int trap(vector<int>& height) 
//     {
//         int n = height.size();
//         int res =  0;
//         for(int i = 0 ; i < n ; i++)
//         {
//             int lmax = height[i];
//             for(int j = 0 ; j < i ; j++)
//             {
//                 lmax = max(lmax , height[j]);
//             }
            
//             int rmax = height[i];
//             for(int j = n-1 ; j >= i ; j --)
//             {
//                 rmax = max(rmax , height[j]);
//             }
            
//             res += min(rmax , lmax) - height[i];
//         }
        
//         return res;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        int res = 0;
        vector<int>lmax(n);
        vector<int>rmax(n);
        
        lmax[0] = height[0];
        rmax[n-1] = height[n-1];
        
        for(int i = 1 ; i < n ; i++)
        {
            lmax[i] = max(height[i] , lmax[i-1]);
        }
        
        for(int i = n-2 ; i >= 0 ; i--)
        {
            rmax[i] = max(height[i] , rmax[i+1]);
        }
        
        for(int i = 1 ; i < n-1 ; i++)
        {
            res += min(rmax[i] , lmax[i]) - height[i];
        }
        
        return res;
    }
};