class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char>stk1,stk2;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '#' && !stk1.empty())
                stk1.pop();
            
            else if(s[i] != '#')
                stk1.push(s[i]);
        }
       
        for(int i = 0 ; i < t.size() ; i++)
        {
            if(t[i] == '#' && !stk2.empty())
                stk2.pop();
            
            else if(t[i] != '#')
                stk2.push(t[i]);
        }
        
        while(!stk1.empty() && !stk2.empty())
        {
            if(stk1.top() != stk2.top())
                return false;
            
            stk1.pop();
            stk2.pop();
        }
        
        return (stk1.empty() && stk2.empty());
    }
};