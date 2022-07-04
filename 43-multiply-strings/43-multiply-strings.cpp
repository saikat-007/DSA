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
                ans[i+j] += digit;//adding the obtained result to its correct place 
				//we increase the position in ans as we move in num1 and num2 
				//because that is how we multiply 2 numbers
				//123
				//x456
				// we first multiply 3 and 6 and add their result at units place which 
				//is 0(of num1)+0(of num2) th position the multiply 6 and 2 and add result in 0+1 th position
                ans[i+j+1] += ans[i+j] / 10; //taking care of carry
                ans[i+j] = ans[i+j] % 10; // modding the original result by 10 to keep our answer in bound
            }
        }
        
        reverse(ans.begin(),ans.end());
        string res="";
        int i=0;
        
        //to avoid leading 0`s
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