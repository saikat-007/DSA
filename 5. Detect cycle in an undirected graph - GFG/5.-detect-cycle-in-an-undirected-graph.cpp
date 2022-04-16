// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool detectCycle(int s, vector<int> adj[], vector<int> &visited)
    {
        queue<pair<int, int>> nodeParent;
        nodeParent.push({s, -1});
        visited[s] = 1;
        while(!nodeParent.empty())
        {
            int node = nodeParent.front().first;
            int parent = nodeParent.front().second;
            nodeParent.pop();
            for(auto u : adj[node])
            {
                if(!visited[u])
                {
                    visited[u] = 1;
                    nodeParent.push({u, node});
                }
                else if(u != parent)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
                if (detectCycle(i, adj, visited))
                        return true;
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