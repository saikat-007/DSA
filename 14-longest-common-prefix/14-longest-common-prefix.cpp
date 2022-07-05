class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string minstr;
        int len = INT_MAX;
        int idx;
        
        for(int i = 0 ; i < strs.size() ; i++)
        {
            if(strs[i].size() < len)
            {
                len = strs[i].size();
                idx = i;
            }
        }
        
        minstr = strs[idx];
        int count = 0;
        for(int i = 0 ; i < len ; i++)
        {
            for(int j = 0 ; j < strs.size() ; j++)
            {
                if(strs[j][i] != minstr[i])
                {
                    return minstr.substr(0,i);
                    break;
                }
            }
            count++;
        }
        
        return minstr.substr(0,count);
    }
};