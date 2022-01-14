class Solution {
public:
    
    string addStrings(string num1, string num2)
    {
        stack<int>s1,s2,sol;
        string res;
        
        for(int i=0;i<num1.size();i++)
            s1.push(num1[i]-'0');
        
        for(int i=0;i<num2.size();i++)
            s2.push(num2[i]-'0');
        
        int sum=0,carry=0;
        while(!s1.empty() && !s2.empty())
        {
            int x,y;
            x=s1.top();
            y=s2.top();
            sum=x+y+carry;
            sol.push(sum%10);
            carry=(sum>=10)?1:0;
            s1.pop();
            s2.pop();
        }
        
        while(!s1.empty())
        {
            int a=s1.top();
            int b=a+carry;
            carry=(b>=10)?1:0;
            sol.push(b%10);
            s1.pop();
        }
        
        while(!s2.empty())
        {
            int a=s2.top();
            int b=a+carry;
            carry=(b>=10)?1:0;
            sol.push(b%10);
            s2.pop();
        }
        
        if(carry!=0)
        {
            sol.push(carry);
        }
        
        while(!sol.empty())
        {
            res+=(sol.top()+'0');
            sol.pop();
        }
        
        return res;
    }
};