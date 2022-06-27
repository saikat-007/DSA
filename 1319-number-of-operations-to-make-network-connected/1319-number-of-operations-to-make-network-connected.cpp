class Solution {
public:
    void dfs(vector<vector<int>>& adj , vector<bool>&visited , int src)
    {
        visited[src] = true;
        for(auto it : adj[src])
        {
            if(!visited[it])
                dfs(adj,visited,it);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connection)
    {
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < connection.size() ; i++)    
        {
            int x = connection[i][0];
            int y = connection[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        int count = connection.size();
        
        if(count < n-1)
            return -1;
        
        vector<bool>visited(n,false);
        int reqCables = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
            {
                dfs(adj,visited,i);
                reqCables++;
            }
        }
        
        return reqCables - 1;
    }
};