class Solution {
public:
    
    //visited array is not required as the graph is DAG so the dfs will not run infinite times or endlessly
    
    void dfs(vector<vector<int>>& graph , vector<vector<int>>& paths , vector<int> & currpath , int src , int dest)
    {
        if(src == dest) // if we reach the destination vertex (i.e last vertex) we return push back the currpath array to our answer array
        {
            currpath.push_back(src);
            paths.push_back(currpath);
            return;
        }
        
        currpath.push_back(src);
        
        for(auto it : graph[src])
        {
            dfs(graph,paths,currpath,it,dest);
            currpath.pop_back();              // backtracking
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<vector<int>>paths; // the final ans (all possible paths will be stored here)
        vector<int>currpath;      // to track the current path
        int src = 0;
        int dest = graph.size() - 1;
        
        dfs(graph , paths , currpath , src , dest);
        return paths;
    }
};