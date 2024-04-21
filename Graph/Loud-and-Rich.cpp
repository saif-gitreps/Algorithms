class Solution {
// The description was horrible, The first yt video explained it so well , and implemented the code on my own.
// https://www.youtube.com/watch?v=2VQftGT1gCQ
// the solution revolves around making the graph and then the goal is to find the most quiet (i.e the person with the least quiet value)
// among the graph relation. I think this is a very naive implementation from me.

public:
    int dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> quiet){
        vis[src] = 1;
        int mn = quiet[src];

        for(auto child : adj[src]){
            if(!vis[child]){
                mn = min(mn, dfs(child, adj, vis, quiet));
            }
        }

        return mn;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> adj[n];
        unordered_map<int, int> mp;

        for(int i = 0 ; i < richer.size(); i ++){
            int x = richer[i][1];
            int y = richer[i][0];
            adj[x].push_back(y);
        }

        for(int i = 0; i < n; i ++){
            mp[quiet[i]] = i;
        }

        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            vector<int> vis(n, 0);
            int mn = dfs(i, adj, vis, quiet);
            ans.push_back(mp[mn]);
        }

        return ans;
    }
};
