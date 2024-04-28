class Solution {
public:
    const int INF = 1000000000;
    void dijkstra(int s, vector<int> &d, vector<vector<pair<int, int>>> &adj) {
        int n = adj.size();
        d.assign(n, INF);
        vector<bool> u(n, false);

        d[s] = 0;
        for (int i = 0; i < n; i++) {
            int v = -1;
            for (int j = 0; j < n; j++) {
                if (!u[j] && (v == -1 || d[j] < d[v]))
                    v = j;
            }

            if (d[v] == INF)
                break;

            u[v] = true;
            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < times.size(); i++){
            adj[times[i][0] - 1].push_back({
                times[i][1] - 1,
                times[i][2]
            });
        } 

        vector<int> distance_from_src;
        dijkstra(k - 1, distance_from_src, adj);
        
        int mn = 0;
        for(int i = 0; i < n; i++){
            if(i == k - 1) continue;
            mn = max(mn, distance_from_src[i]);
        }

        return mn == INF ? -1 : mn;
    }
};
