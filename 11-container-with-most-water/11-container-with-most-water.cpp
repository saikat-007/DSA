class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int l=0;
        int r=height.size()-1;
        int max_water=0;
        while(l<r)
        {
            int lh=height[l];
            int rh=height[r];
            int min_h=min(rh,lh);
            int curr_max=(r-l)*min_h;
            max_water=max(max_water,curr_max);
            if(rh>lh)
                l++;
            else
                r--;
        }
        return max_water;
    }
};