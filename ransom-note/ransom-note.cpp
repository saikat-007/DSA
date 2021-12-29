class Solution {
public:
    bool canConstruct(string r, string m)
    {
        bool res=true;
        int count[256]={0};
        for(int i=0;i<r.length();i++)
            count[r[i]]++;
        for(int i=0;i<m.length();i++)
            count[m[i]]--;
        
        for(int i=0;i<r.length();i++)
        {
            if(count[r[i]]>0)
                res=false;;
        }
        return res;
    }
};