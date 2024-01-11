class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>> &g,vector<int> &path, int u){
        path.push_back(u);
        if(u == g.size() - 1){
            ans.push_back(path);
        }
        else{
            for(auto vertex: g[u]){
                dfs(g, path, vertex);
            }
        }
        // we are poping this because we are pushing at line 5.
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(graph, path, 0);
        return ans;
    }   
};
