class Solution {
// same as is graph bipartie problem.
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        vector<int> color(graph.size(), -1);

        for (auto dislike: dislikes) {
            int x = dislike[0] - 1;
            int y = dislike[1] - 1;

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for(int i = 0; i < graph.size(); i++) {
            
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
