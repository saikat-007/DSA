class Solution {
public:
    string countAndSay(int n) 
    {
        if(n == 1)    
            return "1";
        
        string temp = countAndSay(n-1);
        string str = "";
        
        int i = 0;
        while(i < temp.size())
        {
            char c = temp[i];
            int count = 0;
            
            while(temp[i] == c)
            {
                count++;
                i++;
            }
            
            str += count + '0';
            str += c;
        }
        
        return str;
    }
};