class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int min=INT_MAX;
        string str;
        for(int i=0;i<strs.size();i++)
        {
            int len = strs[i].size();
            if(len < min)
            {
                min = len;
                str = strs[i];
            }
        }
        
        int count = 0;
        for(int i = 0 ; i < str.size() ; i++)
        {
            for(int j = 0 ; j < strs.size() ; j++)
            {
                 if(strs[j][i] != str[i])
                        return str.substr(0,count);  
            }
            count++;
        }
        
        return str.substr(0,count);
    }
};