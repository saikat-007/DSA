class Solution {
public:
    
    bool isValid(string s) 
    {
        stack<char>stk;
        char c;
        for(int i=0;i<s.length();i++)
        {
            c=s[i];
            
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk.push(c);
            
            else if(c==')')
            {
                if(stk.empty()==false && stk.top() == '(')
                    stk.pop();
                
                else
                    return 0;
            }
            
            else if(c=='}')
            {
                if(stk.empty()==false && stk.top() == '{')
                    stk.pop();
                
                else
                    return 0;
            }
            
            else
            {
                if(stk.empty()==false && stk.top() == '[')
                    stk.pop();
                
                else
                    return 0;
            }
        }
        
        if(stk.empty() == true)
            return true;
        
        else
            return false;
    }
};