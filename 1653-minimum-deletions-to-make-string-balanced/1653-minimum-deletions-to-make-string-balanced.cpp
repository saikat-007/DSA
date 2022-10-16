class Solution {
public:
    int minimumDeletions(string s) 
    {
        int n = s.size();
        vector<int>b_on_left(n,0);
        vector<int>a_on_right(n,0);
        
        int b_count = 0;
        for(int i = 0 ; i < n ; i++)
        {
            b_on_left[i] = b_count;
            
            if(s[i] == 'b')
                b_count++;
        }
        
        int a_count = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            a_on_right[i] = a_count;
            
            if(s[i] == 'a') 
                a_count++;
        }
        
        int res = INT_MAX;
        for(int i = 0 ; i < n ; i++)
        {
            res = min(res,a_on_right[i] + b_on_left[i]);
        }
        
        return res;
    }
};