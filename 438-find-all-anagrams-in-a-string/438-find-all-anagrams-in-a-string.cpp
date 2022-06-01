class Solution {
public:
    /*
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
    
    vector<int> findAnagrams(string s, string p)
    {
        int l = p.size();
        vector<int>ans;
        if(p.length() > s.length()) return ans;
        for(int i = 0 ; i < (s.size() - l + 1) ; i++)
        {
            string temp = s.substr(i,l);
            if(isanagram(p,temp))
                ans.push_back(i);
            
        }
        
        return ans;
    }
};

*/
    vector<int> findAnagrams(string s, string p)
    {
        vector<int>ans;
        vector<int>hash(26,0);
        vector<int>phash(26,0);
        int window = p.size();
        int l = s.size();
        if(l < window)
            return ans;
        
        int left = 0 , right = 0;
        for(right = 0 ; right < window ; right++)
        {
            phash[p[right]-'a']++;
            hash[s[right]-'a']++;
        }
        right--;
        while(right < l)
        {
            if(phash == hash)
                ans.push_back(left);
            
            right++;
            if(right != l)
                hash[s[right] - 'a']++;
            hash[s[left] - 'a']--;
            left++;
        }
        return ans;
    }
};