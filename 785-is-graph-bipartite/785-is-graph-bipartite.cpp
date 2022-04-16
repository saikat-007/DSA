class Solution {
public:
    
    //key idea : bipartite graph is a graph which can be colored using 2 color such that no two adjascent node have same color
    
    bool Bipartite(int s,vector<vector<int>>graph,vector<int>&color)
    {
        color[s] = 1;
        queue<int>q;
        q.push(s);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            for(auto it : graph[curr])
            {
                if(color[it] == -1)
                {
                    color[it] = 1 - color[curr];   // for flipping color 1-> red 0 -> blue -1 -> no color
                    q.push(it);
                }
                
                else if(color[curr] == color[it])
                    return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph)
    {
        vector<int>color(graph.size(),-1);
        for(int i = 0 ; i < graph.size() ; i++)
        {
            if(color[i] == -1)
                if(!Bipartite(i,graph,color))
                    return false;
        }
        
        return true;
    }
};