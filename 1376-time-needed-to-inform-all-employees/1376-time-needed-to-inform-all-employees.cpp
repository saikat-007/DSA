class Solution {
public:
    void dfs(int src , int &res , int curr , vector<int>&informTime , vector<vector<int>>&adj)
    {
        curr+=informTime[src];
        
        for(auto it : adj[src])
        {
            dfs(it,res,curr,informTime,adj);
        }
        
        res = max(res,curr);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<vector<int>>adj(n);
        int src;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
            
            else
                src = i;
        }
        
        int res = 0;
        dfs(src,res,0,informTime,adj);
        return res;
    }
};