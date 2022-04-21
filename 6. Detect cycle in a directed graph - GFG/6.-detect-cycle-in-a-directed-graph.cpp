// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkForCycle(vector<int> adj[] , int s , vector<bool>&visited , vector<bool>&dfsVisited)
    {
        visited[s] = true;
        dfsVisited[s] = true;
        
        for(auto x : adj[s])
        {
            if(!visited[x])
                checkForCycle(adj,x,visited,dfsVisited);
                
            if(visited[x] == true)
                if(dfsVisited[x] == true)
                    return true;
        }
        
        dfsVisited[s] = false;
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool>visited(V,false);
        vector<bool>dfsVisited(V,false);
        
        for(int i = 0 ; i < V ; i++)
        {
            if(visited[i] == false)
                if(checkForCycle(adj,i,visited,dfsVisited))
                    return true;
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends