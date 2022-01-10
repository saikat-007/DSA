class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>&a)
    {
        vector<vector<int>>res;
        if(a.size() == 0)
            return res;
        sort(a.begin(),a.end());
        res.push_back(a[0]);
        
        int j=0;
        
        for(int i=1;i<a.size();i++)
        {
            //if intevals are overlapping
            if(res[j][1] >= a[i][0])
                res[j][1] = max(res[j][1],a[i][1]);
            
            //if intevals are not overlapping
            else
            {
                j++;
                res.push_back(a[i]);
            }
        }
        
        return res;
    }
};