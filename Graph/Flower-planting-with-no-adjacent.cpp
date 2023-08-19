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


class Solution {
// ok so my mistake was i didnt make a graph out of it.
public:
    vector<bool> visited;
    vector<vector<int>> paths;
    Solution(){
        visited.resize(10000);
        paths.resize(10000);
    }
    void bfs(int source,int n,vector<int> &valid_path){
        queue<int> q;
        q.push(source);
        while(q.empty()==false){
            int temp = q.front();
            q.pop();
            valid_path.push_back(temp);
            if(valid_path.size()==n){
                return;
            }
            for(auto s: paths[temp]){
                if(!visited[s]){
                    visited[s] = true;
                    q.push(s);
                }
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& a) {
        vector<int> valid_path;
        for(int i = 0 ; i < a.size(); i++ ){
            paths[a[i][0]].push_back(a[i][1]);
            paths[a[i][1]].push_back(a[i][0]);
        }
        bfs(1,n,valid_path);
        if(valid_path.size()<n){
            int existing_limit = valid_path.size();
            int k = 0;
            for(int i=0;i<n-existing_limit;i++){
                valid_path.push_back(valid_path[k]);
                ++k;
                if(k >= existing_limit){
                    k = 0 ;
                    continue;
                }
                //valid_path.push_back(valid_path[k]);
                //++k;
            } 
        }
        return valid_path;
    }
};


class Solution {
//this worked till  7 test cases, not working for more.
public:
    vector<bool> visited;
    vector<vector<int>> paths;
    Solution(){
        visited.resize(10000);
        paths.resize(10000);
    }
    void bfs(int source,int n,vector<int> &valid_path){
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(q.empty()==false){
            int temp = q.front();
            q.pop();
            valid_path.push_back(temp);
            if(valid_path.size()==n){
                return;
            }
            for(auto s: paths[temp]){
                if(!visited[s]){
                    visited[s] = true;
                    q.push(s);
                }
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& a) {
        vector<int> valid_path;
        for(int i = 0 ; i < a.size(); i++ ){
            paths[a[i][0]].push_back(a[i][1]);
            paths[a[i][1]].push_back(a[i][0]);
        }
        bfs(1,n,valid_path);
        if(valid_path.size()<n){
            int existing_limit = valid_path.size();
            int k = 0;
            for(int i=0;i<n-existing_limit;i++){
                if(k >= existing_limit){
                    k = 0 ;
                }
                else{
                    valid_path.push_back(valid_path[k]);
                    ++k;
                }
            } 
        }
        return valid_path;
    }
};
