class Solution {
public:
    char findTheDifference(string s, string t)
    {
//         int visited[26]={0};
//         for(int i=0;i<t.size();i++)
//         {
//             visited[t[i]-'a']++;
//         }
        
//         for(int i=0;i<s.size();i++)
//         {
//              visited[s[i]-'a']--;
//         }
        
//         int res;
//         for(int i=0;i<26;i++)
//         {
//             if(visited[i]!=0)
//                 res = i;
//         }
//         return res+'a';
        
        int sum1=0,sum2=0;
        for(int i=0;i<t.size();i++)
        {
            sum1+=(t[i]-'a');
        }
        for(int i=0;i<s.size();i++)
        {
            sum2+=(s[i]-'a');
        }
        return (sum1-sum2)+'a';
    }
};