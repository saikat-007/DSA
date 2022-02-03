class Solution {
public:
    
    bool ispal(string str,int low,int high)
    {
        while(low<high)
        {
            if(str[low]!=str[high])
            {
                return false;
                break;
            }
            else
            {
                low++;
                high--;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s)
    {
        int low=0;
        int high=s.size()-1;
        
        bool case1,case2;
        while(low<high)
        {
            if(s[low]==s[high])
            {
                low++;
                high--;
            }
            
            else
            {
                return ispal(s,low+1,high)|| ispal(s,low,high-1);
            }
        }
     
        return true;
    }
};