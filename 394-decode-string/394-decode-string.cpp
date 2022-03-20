class Solution {
public:
    
    string crackPassword(string &s,int &i,int size)
    {
        string res;
        while(i<size && s[i]!=']')
        {
            if(isdigit(s[i]))
            {
                int k=0;
                while(i<size && isdigit(s[i]))
                {
                    k=k*10+s[i++]-'0';   // for getting the number before opening bracket
                }
                i++;   // to skip opening bracket
                string temp = crackPassword(s,i,size);

                while(k>0)
                {
                    res+=temp;
                    k--;
                }

                i++; // for skipping closing brackets

            }
            else
                res+=s[i++];
        }

        return res;
    }
    
    string decodeString(string s) 
    {
        int size = s.size();
        int i=0;
        return crackPassword(s,i,size);
    }
};