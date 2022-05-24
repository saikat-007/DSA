class Solution {
public:
    int longestValidParentheses(string s)
    {
//         stack<char>stk;
//         int count = 0;
//         int m = 0;
        
//         int i = 0;
        
//         while(i<s.size())
//         {
            
//             if(s[i] == '(')
//             {
//                 stk.push(s[i]);
//             }
            
//             else if(s[i] == ')' && stk.top() == '(')
//             {
//                 stk.pop();
//                 count+=2;
//                 m = max(m,count);
//             }
        
//             else 
//             {
//                 count = 0;
//             }
            
            
//             i++;
//         }
        
//         return m;
        
        int m = 0;
        stack<int>stk;
        stk.push(-1);
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '(')
                stk.push(i);
            
            else
            {
                stk.pop();
                if(stk.empty())
                    stk.push(i);
                
                else
                    m=max(m,i-stk.top());
            }
        }
        
        return m;
    }
};