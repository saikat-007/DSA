class Solution {
public:
    string reverseVowels(string s)
    {
        string vowel = "";
        string st = "aeiouAEIOU";
        for(char c : s)
        {
            if(st.find(c) != string :: npos)
            {
                vowel+=c;
            }
        }
        
        reverse(vowel.begin(),vowel.end());
        int k = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(st.find(s[i]) != string::npos)
            {
                s[i] = vowel[k];
                k++;
            }
        }
        
        return s;
    }
};