class Solution {
public:
    void getreversed(string &s , int low , int high)
    {
        
    }
    
    string reverseWords(string s)
    {
        string result;
        int n = s.size();
        int i = 0;
        while(i < n)
        {
            while(i < n && s[i] == ' ')
            {
                i++;
            }

            if(i >= n) break;

            int j = i+1;
            while(j < n && s[j] != ' ')
            {
                j++;
            }

            string sub = s.substr(i,j-i);

            if(result.size() == 0) result = sub;
            else
                result=sub + " " +result;
            i=j+1;
        }
        
        return result;
    }
};