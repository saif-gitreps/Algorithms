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


    void dfsCountAndUpdate(int node, int prevNode, vector<vector<int>>& adjVec,
                           string& labels, vector<int>& solution, vector<int>& freqMap) {
        int prevCount = freqMap[labels[node] - 'a'];

        freqMap[labels[node] - 'a'] += 1;
        
        for (int nextNode : adjVec[node]) {
            if (prevNode == nextNode) continue;
            dfsCountAndUpdate(nextNode, node, adjVec, labels, solution, freqMap);
        }

        solution[node] = freqMap[labels[node] - 'a'] - prevCount;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjVec(n, vector<int>());

        for (vector<int>& edge : edges) {
            adjVec[edge[0]].push_back(edge[1]);
            adjVec[edge[1]].push_back(edge[0]);
        }

        vector<int> solution(n, 0);
        vector<int> freqMap = vector<int>(26, 0);
        dfsCountAndUpdate(0, 0, adjVec, labels, solution, freqMap);

        return solution;
    }
};
