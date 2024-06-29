class Solution {
// I mean i have been trying since morning, its 6 now . Atleast it shows TLE.
public:
    void dfs(int src, int current_level,vector<int> &vis, vector<vector<int>> adj) {
        vis[src] = current_level;

        for (auto child : adj[src]) {
            if (!vis[child]) {
                dfs(child, current_level + 1, vis, adj);
            }
        }   

    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 0);
        vector<vector<int>> adj(n);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0 ; i < n ; i++) {
            vector<int> vis(n, 0);
            dfs(i, 1, vis, adj);
            int count = 0;
            
            for (int j = 0 ; j < n; j++) {
                count += (vis[j] - 1);
            }

            ans[i] = count;
        }

        return ans;
    }
};
