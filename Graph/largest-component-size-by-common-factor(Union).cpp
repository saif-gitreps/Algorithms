class Solution {
// Naive BFS attemp, doesnt work. 30/100 cases.
public:
    int dfs(int src, vector<vector<int>> &adj, vector<int> &vis){
        vis[src] = 1;
        int mx = 1;
        for(auto child : adj[src]){
            if(!vis[child]) {
                mx = max(mx, 1 + dfs(child, adj, vis));
            }
        }
        return mx;
    }
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && __gcd(nums[i], nums[j]) > 1){
                    adj[i].push_back(j);
                }
            }
        }
        int mx = 0;
        for(int i = 0; i < n ; i++) {
            vector<int> vis(n, 0);
            mx = max(mx, dfs(i, adj, vis));
        }

        return mx;
    }
};

class Solution {
// This one works but TLE at 74.
// idea is by using DSU, We will make a union if they both have a common gcd > 1.
// then return the max size of each parent node.
public:
    vector<int> parent;
    vector<int> size;

    void Make(int v){
        parent[v] = v;
        size[v] = 1;
    }

    int find(int v){
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){
            return;
        }
        if(size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }

    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++){
            Make(i);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && __gcd(nums[i], nums[j]) > 1){
                    Union(i, j);
                }
            }
        }
        int mx = 1;
        for(int i = 0; i < n ; i++) {
            mx = max(mx, size[i]);
        }

        return mx;
    }
};
