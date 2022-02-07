class Solution {
public:
    char findTheDifference(string s, string t)
    {
        int visited[26]={0};
        for(int i=0;i<t.size();i++)
        {
            visited[t[i]-'a']++;
        }
        
        for(int i=0;i<s.size();i++)
        {
             visited[s[i]-'a']--;
        }
        
        int res;
        for(int i=0;i<26;i++)
        {
            if(visited[i]!=0)
                res = i;
        }
        return res+'a';
    }
};