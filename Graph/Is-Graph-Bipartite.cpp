class Solution {
// this one didnt work because theres some component thing , maybe because we had to check each and every node individually.
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;

        q.push(0);

        vector<int> color(graph.size(), -1);
        color[0] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto child : graph[node]){
                if(color[child] == -1){
                    color[child] = (color[node] == 0) ? 1 : 0;
                    q.push(child);
                }
                else if(color[child] == color[node]){
                    return false;
                }
            }

        }
        return true;
    }
};


class Solution {
// works , [[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]] <- study this example.
public:
    bool bfs(int source, vector<vector<int>>& graph, vector<int> &color){
         queue<int> q;

        q.push(source);

        color[source] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto child : graph[node]){
                if(color[child] == -1){
                    color[child] = (color[node] == 0) ? 1 : 0;
                    q.push(child);
                }
                else if(color[child] == color[node]){
                    return false;
                }
            }

        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i = 0; i < graph.size(); i++){
            
            if(color[i] == -1){
                
                bool check = bfs(i, graph, color);
                
                if(check == false){
                    
                    return false;
                }
            }
        }
        return true;        
    }
};
