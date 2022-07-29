class Solution {
public:
    
    string getDecoded(string &s , int &i)
    {
        string ans = "";
        int num = 0;
        while(i < s.size() && s[i] != ']')
        {
            if(isdigit(s[i]))
            {
                num = num*10 + (s[i] - '0');
            }
            
            else if(s[i] == '[')
            {
                ++i;
                string temp = getDecoded(s,i);
                while(num > 0)
                {
                    ans += temp;
                    num --;
                }
            }
            
            else
            {
                ans += s[i];
            }
            i++;
        }
        
        return ans;
    }
    
    string decodeString(string s)
    {
        int idx = 0;
        return getDecoded(s,idx);
    }
};