class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int>res;
        int i=0,j=0;
        while(i<a.size() && j<b.size())
        {
            if(a[i]>b[j])
                j++;
            
            else if(a[i]<b[j])
                i++;
            
            else
            {
                res.push_back(a[i]);
                i++;j++;
            }
            
        }
        return res;
    }
};