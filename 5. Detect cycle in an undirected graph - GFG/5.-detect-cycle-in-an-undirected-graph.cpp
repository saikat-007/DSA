// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfsRec(int s,int parent,vector<int> adj[],vector<int>& visited)
    {
        visited[s]=1;
        for(auto x : adj[s])
        {
            if(!visited[x])
                {
                    if(dfsRec(x,s,adj,visited) == true)
                        return 1;
                }
                
            else if(x!=parent)
                return true;
        }
        
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int>visited(v+1,0);
        int parent = -1;
        for(int i = 0 ; i < v ; i++)
        {
            if(!visited[i])
                {
                    if(dfsRec(i,-1,adj,visited))
                        return true;
                }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends