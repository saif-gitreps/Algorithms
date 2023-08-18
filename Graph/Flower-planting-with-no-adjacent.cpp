class Solution {
// first attempt, the logic seems right , but idk why i am getting error. 
public:
    vector<bool> visited;
    Solution(){
        visited.resize(10000);
    }
    void bfs(vector<vector<int>>& paths,int source,int n,vector<int> &valid_path){
        queue<int> q;
        q.push(source);
        while(q.empty()==false){
            int temp = q.front();
            q.pop();
            valid_path.push_back(temp);
            for(auto s: paths[temp]){
                if(!visited[s]){
                    visited[s] = true;
                    q.push(s);
                }
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> valid_path;
        bfs(paths,1,n,valid_path);
        if(valid_path.size()<n){
            int existing_limit = valid_path.size();
            int k = 0;
            for(int i=0;i<n-existing_limit;i++){
                if(k >= existing_limit){
                    k = 0 ;
                }
                valid_path.push_back(valid_path[k++]);
            } 
        }
        return valid_path;
    }
};
