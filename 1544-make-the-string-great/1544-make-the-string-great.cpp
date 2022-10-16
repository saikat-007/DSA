class Solution {
public:
    string makeGood(string s)
    {
        stack<char>stk;
        int n = s.size();
        int i = 0;
        
        while(i < n)
        {
            if(!stk.empty() && (abs(stk.top() - s[i]) == 32))
                stk.pop();
            else
                stk.push(s[i]);
            
            i++;
        }
        
        string res = "";
        
        while(!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        
        reverse(res.begin() , res.end());
        return res;
    }
};