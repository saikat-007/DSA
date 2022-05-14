class Solution {
public:
    bool dfs(vector<bool>&visited , vector<bool>&dfsVisited , vector<bool> &unsafe ,vector<vector<int>> &graph , int s)
    {
        visited[s]=true;
        dfsVisited[s]=true;
        
        for(auto x : graph[s])
        {
            if(!visited[x])
            {
                if(dfs(visited , dfsVisited , unsafe , graph , x) == true)
                {
                    unsafe[s] = true;
                    return true;
                }
            }
            
            else
            {
                if(visited[x] && dfsVisited[x])
                {
                    unsafe[s] = true;
                    return true;
                }
            }
        }
        
        dfsVisited[s] = false;
        return false;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<bool>visited(n,false);
        vector<bool>dfsVisited(n,false);
        vector<bool>unsafe(n,false);
        vector<int>safe;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
                dfs(visited , dfsVisited , unsafe , graph , i);
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            if(!unsafe[i])
                safe.push_back(i);
        }
        
        return safe;
    }
};