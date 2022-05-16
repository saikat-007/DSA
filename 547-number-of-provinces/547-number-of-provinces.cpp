class Solution {
public:
    void dfs(int s , vector<vector<int>>& adj , vector<bool> &visited)
    {
        visited[s] = true;
        for(auto x : adj[s])
        {
            if(!visited[x])
                dfs(x,adj,visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int v = isConnected.size();
        vector<vector<int>>adj(v+1);
        
        for(int i = 1 ; i <= v ; i++)
        {
            for(int j = 1 ; j <= v ; j++)
            {
                if(isConnected[i-1][j-1] == 1 && (i-1) != (j-1))
                    adj[i].push_back(j);
            }
        }
        
        vector<bool>visited(v+1,false);
        int count = 0;
        
        for(int i = 1 ; i <= v ; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,adj,visited);
            }
        }
        
        return count;
    }
};