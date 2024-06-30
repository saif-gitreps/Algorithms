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

class Solution {
// this is the first time i used anonymouse function in C++, anyway so 
// what i learnt is that we dont need to run DFS with level calculator to find the ans of each node
// Here first we use dfs to find the number of sub nodes including the node itself and 
// try to calculate the distance of node 0 or the first node. Also some partial calculation of ans
// also happens in the first DFS itself.
// second DFS is preOrder, where We take Distance[i] = Distance[Root] - Nodes getting closer to the pointer + Nodes getting farther from the pointer.
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 0);
        vector<int> count_sub(n, 1);
        vector<vector<int>> adj(n);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        function<void(int, int)> dfs1 = [&](int src, int parent) {
            for (auto child : adj[src]) {
                if(child == parent) continue;

                dfs1(child, src);
                count_sub[src] += count_sub[child];
                ans[src] += ans[child] + count_sub[child]; 
            }
        };

        function<void(int, int)> dfs2 = [&](int src, int parent) {
            for (auto child : adj[src]) {
                if(child == parent) continue;

                ans[child] = ans[src] - count_sub[child] + (n - count_sub[child]); 
                dfs2(child, src);
            }
        };

        dfs1(0, -1);
        dfs2(0, -1);

        return ans;
    }
};
