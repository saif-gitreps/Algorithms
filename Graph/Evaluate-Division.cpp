class Solution {
// i understood the solution.
public:
    map<string, vector<pair<string , double>>> buildGraph(vector<vector<string>>& equations, vector<double>& values){
         map<string, vector<pair<string, double>>> mp;
         int n = values.size();

         for(int i = 0; i < n; i++){
            string src = equations[i][0];
            string dest = equations[i][1];

            mp[src].push_back({dest, values[i]});
            mp[dest].push_back({src, 1 / values[i]});
         }
         return mp;
    }

    double dfs(string src, string dest, unordered_set<string> vis, map<string, vector<pair<string, double>>> &mp){
        if(!mp.count(src) or !mp.count(dest)){
            return -1.0;
        }
        if(src == dest){
            return 1.0;
        }
        vis.insert(src);

        for(auto child: mp[src]){
            if(!vis.count(child.first)){
                double ans = dfs(child.first, dest, vis, mp);
                if(ans != -1.0){
                    ans *= child.second;
                    return ans;
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> mp = buildGraph(equations, values);
        int n = queries.size(); 
        vector<double> ans;
        unordered_set<string> visited;

        for(int i = 0; i < n; i++){
            double result = dfs(queries[i][0], queries[i][1], visited, mp);
            ans.push_back(result);
        }

        return ans;

    }
};
