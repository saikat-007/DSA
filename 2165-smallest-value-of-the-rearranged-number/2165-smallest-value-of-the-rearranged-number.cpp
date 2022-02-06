class Solution {
public:
    long long smallestNumber(long long num)
    {
        if(num==0)
            return 0;
        
        string res=to_string(num);
        if(res[0] == '-')
        {
            sort(res.begin()+1,res.end(),greater<int>());
        }
        
        else
        {
            sort(res.begin(),res.end());
            for(int i=0;i<res.size();i++)
            {
                if(res[i]=='0' && res[i+1]!='0')
                {
                    swap(res[0],res[i+1]);
                    break;
                }
            }
        }
        
        return stoll(res);
    }
};