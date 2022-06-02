class Solution {
public:
    bool isanagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        
        int count[26]={0};
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++)
        {
           if(count[i] !=  0)
           {
               return false;
               break;
           }
        }
        return true;
    }
    
  
    bool checkInclusion(string p, string s)
    {
        int l = p.size();
        if(p.length() > s.length()) return false;
        for(int i = 0 ; i < (s.size() - l + 1) ; i++)
        {
            string temp = s.substr(i,l);
            if(isanagram(p,temp))
                return true;
        }
        
        return false;
    }
};