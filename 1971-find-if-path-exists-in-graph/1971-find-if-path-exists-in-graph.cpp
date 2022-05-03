class Solution {
public:
    
    void bfs(vector<bool>&visited , vector<int>adj[] ,int s)
    {
        queue<int>q;
        visited[s] = true;
        q.push(s);
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            for(auto x : adj[u])
            {
                if(!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<int>adj[n];
        
        for(auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<bool>visited(n+1,false);
        
        bfs(visited , adj , source);
        
        return visited[destination];
    }
};