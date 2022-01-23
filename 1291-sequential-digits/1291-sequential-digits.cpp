class Solution {
public:
    
    vector<int>ans;
    
    void get_res(int low,int high,int i,int n)
    {
        if(n>=low && n<=high)
            ans.push_back(n);
        
        if(n>high || i>9)
            return;
        
        get_res(low,high,i+1,n*10+i);
    }
    
    vector<int> sequentialDigits(int low, int high)
    {
        for(int i=1;i<=9;i++)
        {
            get_res(low,high,i,0);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};