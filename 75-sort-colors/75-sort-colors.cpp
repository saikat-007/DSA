class Solution {
public:
    void sortColors(vector<int>& a) {
        vector<int>count(3,0);
        for(int i=0;i<a.size();i++)
            count[a[i]]++;
        
        for(int i=1;i<3;i++)
        {
            count[i]=count[i]+count[i-1];
        }
        
        vector<int>output(a.size(),0);
        for(int i=a.size()-1;i>=0;i--)
        {
            output[count[a[i]]-1]=a[i];
            count[a[i]]--;
        }
        
        for(int i=0;i<a.size();i++)
        {
            a[i]=output[i];
        }
    }
};