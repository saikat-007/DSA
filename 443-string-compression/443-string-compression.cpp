class Solution {
public:
    int compress(vector<char>& chars)
    {
        vector<char>res;
        
        if(chars.size() == 1)
            return 1;
        
        chars.push_back(NULL);
        
        int i=1;
        int count=1;
        while(i<chars.size())
        {
            if(chars[i]==chars[i-1])
            {
                count++;
                i++;
            }
            else
            {
                if(count > 1)
                {
                    res.push_back(chars[i-1]);
                    string s = to_string(count);
                    for(char digit : s)
                        res.push_back(digit);
                    i++;
                    count=1;
                }
                
                else
                {
                    res.push_back(chars[i-1]);
                    i++;
                }
            }
        }
        
        for(int i=0;i<res.size();i++)
        {
            chars[i]=res[i];
        }
        
        return res.size();
    }
};