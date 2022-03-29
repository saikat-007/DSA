class Solution {
public:
    int findDuplicate(vector<int>& arr)
    {
        int n = arr.size();
        vector<int>map(n+1);
        int res;
        
        for(int i = 0 ; i < n ; i++)
        {
            map[arr[i]]++;
        }
        
        for(int i = 0 ; i < n + 1 ; i++)
        {
            if(map[i] > 1)
            {
                res = i;
            }
        }
        
        return res;
    }
};