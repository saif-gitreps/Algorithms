class Solution {
public:
// passed like 80/180 cases.
    bool equationsPossible(vector<string>& equations) {
        unordered_map<string, int> mp;
        for(int i = 0; i < equations.size(); i++){
            string str = ""; 
            str += equations[i][1];
            str += equations[i][2];
            mp[str]++;
        }

        if(mp["=="] == equations.size() || mp["!="] == equations.size()){
            return true;
        } else{
            return false;
        }
    }
};


class Solution {
// I would say a better attempt, passing 130 / 180 casese.
public:
    bool dfs(int src, vector<int> &vis, vector<vector<pair<int, string>>> &adj){
        vis[src] = 2;
    
        for(auto child : adj[src]){
            if(!vis[child.first]){
                if (!dfs(child.first, vis, adj)){
                    return false;
                }
            }
            else if(vis[child.first] == 2){
                string sign1 = child.second;
                string sign2 = "";
                for(auto parent : adj[child.first]){
                    if(parent.first == src){
                        sign2 = parent.second;
                        break;
                    }
                }
                if(sign1 != sign2){
                    return false;
                }
                else if(sign1 == "!=" && src == child.first){
                    return false;
                }
            }
        }
    
        vis[src] = 1;
        return true;
    }
    bool equationsPossible(vector<string>& eq) {
        vector<vector<pair<int, string>>> adj(27);
        for(int i = 0; i < eq.size(); i++){
            int s = eq[i][0] - 'a';
            int d = eq[i][3] - 'a';
            
            string str = "";
            str += eq[i][1];
            str += eq[i][2]; 

            adj[s].push_back({d, str});
        }

        vector<int> vis(26, 0);
        for(int i = 0; i < eq.size(); i++){
            int s = eq[i][0] - 'a';
            if(vis[s] < 2){
                if(!dfs(s, vis, adj)){
                    return false;
                }
            }
        }

        return true;
    }
};
