class Solution {
public:
    vector<string> getCombination(string &digits , int i , map<int,string>&mp)
    {
        if(i == digits.size())
            return {""};
        
        vector<string>temp = getCombination(digits , i+1 , mp);
        
        vector<string>res;
        
        for(auto x : mp[digits[i]- '0'])
        {
            for(auto y : temp)
            {
                res.push_back(x+y);
            }
        }
        
        return res;
    }
    vector<string> letterCombinations(string digits)
    {
        if(digits.size() == 0)    
            return {};
        
        map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        return getCombination(digits,0,mp);
    }
};