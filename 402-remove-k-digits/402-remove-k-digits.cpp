class Solution {
public:
    
    //idea: whenever we find a peak element we remove it and decrease the index by 1 we do it untill k becomes 0
    
    string removeKdigits(string num, int k)
    {
        if(num.size() == k)
            return "0";
        
        int i=0;
        while(k>0)
        {
            i=(i>0)?i-1:0;
            while(i<num.size()-1 && num[i]<=num[i+1])
                i++;
            num.erase(num.begin()+i);
            k--;
        }
        
    //for removing leading zeroes
        
        auto non_zero = num.find_first_not_of("0");
        num.erase(0,non_zero);
        
    //this if conditition is for those cases when the string only have 0s like "0" or "000"
        if(num.length() == 0)
            return "0";
        
        return num;
    }
};