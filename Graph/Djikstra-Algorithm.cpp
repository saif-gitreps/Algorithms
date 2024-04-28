/*
  Description in case your dumbass forgets next time:
  https://cp-algorithms.com/graph/dijkstra.html
*/

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

// p stores all the predecessors. we can access it recursively 
// like 1 -> 3 - > 2 - > 4.

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
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
                p[to] = v;
            }
        }
    }
}

/*
  After performing all the iterations array  
  $d[]$  stores the lengths of the shortest paths to all vertices, and array  
  $p[]$  stores the predecessors of all vertices (except starting vertex  
  $s$ ). The path to any vertex  
  $t$  can be restored in the following way:

  array returning traversed path from s to a any node t.

*/

vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}
