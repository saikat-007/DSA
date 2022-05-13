class Solution {
public:
    bool checkBipartite(vector<vector<int>>& graph, int s , vector<int>&color)
    {
        color[s] = 1;
        queue<int>q;
        
        q.push(s);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
           for(auto x : graph[curr])
           {
               if(color[x] == -1)
               {
                   color[x] = 1 - color[curr];
                   q.push(x);
               }
               
               else
               {
                   if(color[x] == color[curr])
                       return false;
               }
           }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<bool>visited(n,false);
        vector<int>color(n,-1) ;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(color[i] == -1)
                if(checkBipartite(graph , i , color) == false)
                    return false;
        }
        
        return true;
    }
};