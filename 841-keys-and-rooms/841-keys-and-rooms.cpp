class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms , int src , vector<bool>&visited)
    {
        visited[src] = true;
        for(auto adj : rooms[src])
        {
            if(!visited[adj])
                dfs(rooms,adj,visited);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n = rooms.size();
        vector<bool>visited(n,false);
        int src = 0;
        dfs(rooms , src , visited);
        for(int i = 0  ; i < visited.size() ; i++)
        {
            if(!visited[i])
                return false;
        }
        
        return true;
    }
};