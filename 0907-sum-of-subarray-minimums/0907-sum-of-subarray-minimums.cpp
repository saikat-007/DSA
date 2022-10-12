class Solution {
public:
//      int sumSubarrayMins(vector<int>& arr) 
//     {
//         int sum = 0;
//         for(int i = 0 ; i < arr.size() ; i++)
//         {
//             int mini = INT_MAX;
//             for(int j = 0 ; j < arr.size() ; i++)
//             {
//                 mini = min(mini,arr[j]);
//                 sum += mini;
//             }
//         }
        
//         return sum ;
//     }
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();
        
        vector<int>result(n,0);
        vector<int>previous_less;
        stack<int>stk;
        
        for(int i = 0 ; i < n ; i++)
        {
            while(!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            
            int res = (stk.empty()) ? -1 : stk.top();
            previous_less.push_back(res);
            stk.push(i);
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            result[i] = (previous_less[i] == -1 ? 0 : (result[previous_less[i]])) + (i - previous_less[i]) * arr[i];
        }
        
        int sum = 0;
        int MOD = 1e9 + 7;
        
        for(auto i : result)
        {
            sum = (sum + i) % MOD;
        }
        

        return sum ;
    }
};