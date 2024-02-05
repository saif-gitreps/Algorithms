//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(int src, vector<int> adj[], vector<int> &vis){
        vis[src] = 1;
        // pair because we need to store where it came from.
        queue<pair<int, int>> q;
        // the pair is <node, parent> . parent for src is set to -1 cuz its 0th one
        q.push({src, -1});
        
        while(q.empty() == false){
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            for(auto neighbour : adj[node]){
                if(vis[neighbour] != 1){
                    q.push({neighbour, node});
                    vis[neighbour] = 1;
                }
                // so it is basically saying if you are visited but your parentNode
                // is not this node , then someone else is your parentNode
                else if(parent != neighbour){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int> vis(V+1, 0);
        
        for(int i = 0; i < V; i++){
            if(vis[i] != 1){
                if(bfs(i, adj, vis) == true){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends
