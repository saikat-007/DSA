class Solution {
public:
    //This problem is an application of the problem --> check for cycle in a directed graph
    
    bool check(int s , vector<int>adj[] , vector<int>&visited , vector<int>&dfsVisited)
    {
        visited[s]= true;
        dfsVisited[s] = true;
        
        for(auto x : adj[s])
        {
            if(!visited[x])
                check(x , adj , visited , dfsVisited);
            
            if(visited[x])
                if(dfsVisited[x])
                    return true;
        }
        
        dfsVisited[s] = false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) 
    {
         //First we have to make adjasency list for the dfs call
        
        vector<int>adj[n];
        for(auto x : prerequisites)
        {
            vector<int>temp = x;
            int a = x[0];
            int b = x[1];
            
            adj[a].push_back(b);  //as a is dependent on b
        }
        
        //we have to take 2 boolean vectors for checking cycle(directed)
        
        vector<int>visited(n,false);
        vector<int>dfsVisited(n,false);
            
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
                if(check(i,adj,visited,dfsVisited))
                    return false;
        }
        
        return true;
    }
};