class Solution {
public:
    int countVowelStrings(int n)
    {
        vector<int>count(5,1);
        
        int i = 3;
        while(n > 1)
        {
            for(int i = 3 ; i >= 0 ; i--)
            {
                count[i] = count[i+1]+count[i];
            }
            
            n--;
        }
        
        
        for(int i = 0 ; i < 5; i++)
        {
           cout<<count[i] << " ";
        }
        
        int ans=0;
        for(int i = 0 ; i < 5; i++)
        {
            ans+=count[i];
        }
        
        
        return ans;
    }
};