class Solution {
public:
    
    vector<string>getVector(string &d,int i,map<int,string>&mp)
    {
        if(i == d.size())
            return {""};
        
        vector<string>temp;
        temp=getVector(d,i+1,mp);
        
        vector<string>res;
        for(auto a:mp[d[i]-'0'])
        {
            for(auto x:temp)
            {
                res.push_back(a+x);
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
        
        return getVector(digits,0,mp);
    }
};