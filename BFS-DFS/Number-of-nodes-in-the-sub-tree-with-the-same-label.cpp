class Solution {
// [[0,2],[0,3],[1,2]] <- an edge case which doesnt make sense and everyone is talking about it.
public:
    void dfs(int src, char match, int &count, unordered_map<int, pair<char, vector<int>>> &adj, vector<int> &vis){
        vis[src] = true;
        for(auto child : adj[src].second){
            if(!vis[child]){
                if(adj[child].first == match){
                    count++;      
                }
                dfs(child, match, count, adj, vis);
            }
        }        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, pair<char, vector<int>>> adj;
        for(auto edge : edges){
            adj[edge[0]].second.push_back(edge[1]);  
        } 
        for(int i = 0; i < labels.size(); i++){
            adj[i].first = labels[i];
        }
        vector<int> ans(labels.size(), 1);

        for(int i = 0; i < labels.size(); i++){
            int count = 1;
            vector<int> vis(labels.size());
            dfs(i, adj[i].first, count, adj, vis);
            ans[i] = count;
        }

        return ans;

    }
};


class Solution {
/* 
    Every DFS recursion will have its own count array (res) where we will count the frequency 
    and then tell give  the parent the count of all the labels that were there in the sub tree dfs.
*/
public:
    vector<int> dfs(int src, vector<int> &vis, unordered_map<int, pair<char, vector<int>>> &adj){
        vis[src] = 1;
        vector<int> res(26, 0);
        res[adj[src].first - 'a'] = 1;

        for(auto child : adj[src].second){
            if(!vis[child]){
                vector<int> temp = dfs(child, vis, adj);
                for(int i = 0; i < 26; i++){
                    res[i] += temp[i];
                }
            }
        }

        vis[src] = res[adj[src].first - 'a'];
        return res;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, pair<char, vector<int>>> adj;
        vector<int> vis(n, 0);
        
        for(auto edge : edges){
            adj[edge[0]].second.push_back(edge[1]);  
            adj[edge[1]].second.push_back(edge[0]);
        }

        for(int i = 0; i < n; i++){
            adj[i].first = labels[i];
        } 
        
        dfs(0, vis, adj);

        return vis;
    }
};



class Solution {
// tried solving again, had to relook at the solution.
public:
    vector<int> dfs(int src, vector<int> &vis, unordered_map<int, pair<char, vector<int>>> &adj) {
        vector<int> res(26, 0);
        vis[src] = 1;
        res[adj[src].first - 'a'] = 1;

        for (auto child : adj[src].second) {
            if (!vis[child]) {
                vector<int> temp = dfs(child, vis, adj);

                for (int i = 0; i < 26; i ++) {
                    res[i] += temp[i];
                }
            }
        }

        int src_child_label_counts = res[adj[src].first - 'a'];
        vis[src] = src_child_label_counts;
        return res;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, pair<char, vector<int>>> adj;
        vector<int> ans(n, 0);

        for (auto edge : edges) {
            adj[edge[0]].second.push_back(edge[1]);
            adj[edge[1]].second.push_back(edge[0]);
        } 
        
        for (int i = 0; i < n ; i++) {
            adj[i].first = labels[i];
        }

        dfs(0, ans, adj);

        return ans;
    }
};
