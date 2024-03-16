class Solution {
// idea is that we will visit a node , then mark it 1, also mark the path as 1
// that way if two nodes with different direction were to come accross, then it would not label it as cyclic(because it is not)
// now when we are backtracking , we unmark the path. for the second sentence reason.
// now if a cycle exist then the node will be both visited and pathvisited. causing it to be cycling.

  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src, int vis[], int path[], vector<int> adj[]){
        vis[src] = 1;
        path[src] = 1;
    
        for(auto child: adj[src]){
            if(!vis[child]){
                if (dfs(child, vis, path, adj)){
                    return true;
                }
            }
            else if(path[child]){
                return true;
            }
        }
    
        path[src] = 0;
        return false;
}
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int path[V] = {0};
    
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, vis, path, adj)){
                    return true;
                }
            }
        }
        return false;
    }
};


// similar solution but instead we use one array , 2 for path vis, and 1 for vis.
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src, int vis[], int path[], vector<int> adj[]){
        vis[src] = 1;
        path[src] = 1;
    
        for(auto child: adj[src]){
            if(!vis[child]){
                if (dfs(child, vis, path, adj)){
                    return true;
                }
            }
            else if(path[child]){
                return true;
            }
        }
    
        path[src] = 0;
        return false;
}
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int path[V] = {0};
    
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, vis, path, adj)){
                    return true;
                }
            }
        }
        return false;
    }
};


