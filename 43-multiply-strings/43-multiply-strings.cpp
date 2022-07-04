class Solution {
public:
    string multiply(string num1, string num2)
    {
        if(num1 == "0" || num2 == "0")    
            return "0";
        
        //ans array size is taken as the sum of sizes of the 2 givens nums because the max size of the product can be sum of the sizes of 2 numbers
        vector<int>ans(num1.size() + num2.size() , 0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        for(int i = 0 ; i < num1.size() ; i++)
        {
            for(int j = 0 ; j < num2.size() ; j++)
            {
                int digit = (num1[i] - '0') * (num2[j] - '0');
                ans[i+j] += digit;
                ans[i+j+1] += ans[i+j] / 10;
                ans[i+j] = ans[i+j] % 10;
            }
        }
        
        reverse(ans.begin(),ans.end());
        string res="";
        int i=0;
        while(i < ans.size() && ans[i] == 0)
        {
            i++;
        }
        
        for(int j = i ; j < ans.size() ; j++)
        {
            res+=(ans[j]+'0');
        }
        
        return res;
    }
};