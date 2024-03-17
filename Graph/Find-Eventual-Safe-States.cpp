class Solution {
// apply the same alg as cycle detection for directed graphs.
// basically those nodes which will have cycle will not be taken as safe nodes.
// if it is a safe node, it can never have a cycle.
public:
    bool bfs(int src, vector<int> &vis,vector<vector<int>> &graph){
        vis[src] = 1;
        vis[src] = 2;
        
        for(auto child : graph[src]){
            if(!vis[child] && bfs(child, vis, graph)){
                return true;
            }
            else if(vis[child] == 2){
                return true;
            }
        }
        vis[src] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size() + 1 ,0);
        vector<int> ans;
        // for(int i = 0; i < graph.size(); i ++){
        //     if(!graph[i].size()){
        //         vis[i] = 3;
        //     }
        // }   

        for(int i = 0; i < graph.size(); i++){
            if(!bfs(i , vis, graph)){
                ans.push_back(i);
            }
        }

        // for(int i = 0; i < vis.size(); i++){
        //     if(vis[i] == 3){
        //         ans.push_back(i);
        //     }
        // }

        return ans;
    }
};
