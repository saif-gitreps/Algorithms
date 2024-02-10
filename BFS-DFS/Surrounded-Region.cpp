class Solution {
// worked for half the cases.
public:
    int seq[5] = {0 , 1, 0, -1, 0};
    void dfs(int row, int col, vector<vector<char>> &a){
        if(row < 0 || row == a.size() 
        || col < 0 || col == a[0].size() 
        || a[row][col] == 'X'){
            return;
        }
        int xcount = 0;
        int ocount = 0;
        for(int i = 0; i < 4; i++){
            int r = row + seq[i];
            int c = col + seq[i + 1];
            if(r < 0 || c < 0 || r >= a.size() || c >= a[0].size()){
                continue;
            }
            else{
                if(a[r][c] == 'X') xcount++;
                else ocount++;
            }
        }
        if(xcount + ocount == 4 && ocount < 4){
            a[row][col] = 'X';
        }
        else{
            return;
        }
        dfs(row + 1, col, a);
        dfs(row - 1, col, a);
        dfs(row, col - 1, a);
        dfs(row, col + 1, a);
    }
    void solve(vector<vector<char>>& a) {
        for(int i = 0 ; i < a.size(); i++){
            for(int j = 0 ; j < a[0].size(); j++){
                if(a[i][j] == 'O'){
                    dfs(i, j, a);
                }
            }
        }
    }
};


class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &a){
        if(row < 0 
        || col < 0 
        || row >= a.size() 
        || col >= a[0].size() 
        || a[row][col] != 'O'
        ){
            return;
        }

        a[row][col] = 'L';

        dfs(row - 1, col, a);
        dfs(row + 1, col, a);
        dfs(row, col - 1, a);
        dfs(row, col + 1, a);
    }
    void solve(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
         
        for(int i = 0 ; i < n; i++){
            if(a[i][0] == 'O'){
                dfs(i, 0, a);
            }
            if(a[i][m-1] == 'O'){
                dfs(i, m - 1, a);
            }
        }

        for(int j = 0 ; j < m; j++){
            if(a[0][j] == 'O'){
                dfs(0, j, a);
            }
            if(a[n-1][j] == 'O'){
                dfs(n - 1, j, a);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(a[i][j] == 'O'){
                    a[i][j] = 'X';
                }
                if(a[i][j] == 'L'){
                    a[i][j] = 'O';
                }
            }
        }
    }
};
