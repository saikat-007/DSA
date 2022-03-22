class Solution {
public:
    string getDecoded(string &s , int &i)
    {
        string res;
        int k = 0;
        while(i < s.size() && s[i]!=']')
        {
            
            if(isdigit(s[i]))
            {
                while(i < s.size() && isdigit(s[i]))
                {
                    k=k*10 + (s[i] - '0');
                    i++;
                }
                 
            }
            
            else if(s[i] == '[')
            {
                i++;
                string temp = getDecoded(s,i);
            
                while(k>0)
                {
                  res+=temp;
                  k--;
                }
                
                i++;
               // k=0;
            }
            
            else
                res+=s[i++];
        }
        return res;
        
    }
    string decodeString(string s)
    {
        int i=0;
        return getDecoded(s,i);
    }
};