class Solution {
public:
    string oddString(vector<string>& words)
    {
        unordered_map<string,int>mp;        //using to store the count 
        unordered_map<string,string>ref;   // using to store the reference of the original string
        
        for(auto w : words)
        {
            string s = "";
            for(int i = 0 ; i < w.size() - 1 ; i++)
            {
                int t = w[i+1] - w[i];
                s += to_string(t) + "-";
            }
            
            mp[s]++;
            ref[s] = w;
        }
        
        for(auto i : mp)
        {
            if(i.second == 1)
                return ref[i.first];
        }
        
        return "";
    }
};