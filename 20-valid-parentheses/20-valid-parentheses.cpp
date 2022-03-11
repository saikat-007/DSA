class Solution {
public:
    bool isValid(string s)
    {
        char c;
        int i=0;
        stack<char>stk;
        while(s[i]!='\0')
        {
            c=s[i];
            if(c == '(' || c == '{' || c == '[')
                stk.push(c);
            
            else
            {
                if(c == ')')
                {
                    if(stk.empty() == false && stk.top() == '(')
                        stk.pop();
                    
                    else
                        return 0;
                }
                
                if(c == '}')
                {
                    if(stk.empty() == false && stk.top() == '{')
                        stk.pop();
                    
                    else
                        return 0;
                }
                
                if(c == ']')
                {
                    if(stk.empty() == false && stk.top() == '[')
                        stk.pop();
                    
                    else
                        return 0;
                }
            }
            
            i++;
        }
        
        if(stk.empty())
            return true;
        
        else
            return false;
    }
};