class Solution {
public:
    int calculate(string s)
    {
        int length = s.size();
        if(length == 0) return 0;
        stack<int>stk;
        int curr_number = 0;
        char operation = '+';
        
        for(int i = 0 ; i < length ; i++)
        {
            char x = s[i];
            if(isdigit(x))
                curr_number = (curr_number * 10) + (x - '0');
            
            if(!isdigit(x) && !iswspace(x) || i == length - 1)
            {
                if(operation == '-')
                    stk.push(-curr_number);
                
                else if(operation == '+')
                    stk.push(curr_number);
                
                else if(operation == '*')
                {
                    int stk_top = stk.top();
                    stk.pop();
                    stk.push(curr_number * stk_top);
                }
                
                else if(operation == '/')
                {
                    int stk_top = stk.top();
                    stk.pop();
                    stk.push(stk_top / curr_number);
                }
                
                operation = x;
                curr_number = 0;
            }
        }
        
        int result = 0;
        while(!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }
        
        return result;
    }
};