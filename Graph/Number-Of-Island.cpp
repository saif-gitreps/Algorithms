class Solution {
// we will traverse every element in the matrix and do a bfs on it.
// our bfs rule is we will only push in the q if All 4 direction of elements from the source are islands.
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        queue<pair<int , int>> q;
        int n = grid.size();
        int m = grid[0].size();

        q.push({row, col});

        vector<vector<int>> nei = {{0, -1} , {-1, 0} , {1, 0}, {0, 1}};

        while(q.empty() != true){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++ ){

                int nRow = row + nei[i][0];
                int nCol = col + nei[i][1];

                if(nCol >= 0 && nCol < m && nRow >= 0 && nRow < n){
                    if(!vis[nRow][nCol] && grid[nRow][nCol] == '1'){
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis (n, vector<int> (m, 0));
        int count = 0;

        for(int i = 0 ; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count ++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
};

class Solution {
// this neigbour offset technique is so clever.
// read the code.
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};

class Solution {
// smart dfs solution , just by using the grid array without using visited array.
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
