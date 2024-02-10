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
