class Solution {
public:
    
    vector<string>res;
    
    void getGP(string &s,int open,int close)
    {
        if(open == 0 && close == 0)
        {
            res.push_back(s);
            return;
        }
        
        if(open > 0)
        {
            s.push_back('(');
            getGP(s,open-1,close);
            s.pop_back();
        }
        
        if(close > 0)
        {
            if(open < close)
            {
                s.push_back(')');
                getGP(s,open,close-1);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string s;
        getGP(s,n,n);
        return res;
    }
};