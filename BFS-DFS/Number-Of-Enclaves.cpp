class Solution {
// EASY PEASY. similar to surrounded-region problem
public:
    void bfs(int i , int j, vector<vector<int>> &a){
        if(i < 0 || j < 0 || i >= a.size() || j >= a[0].size() 
        || a[i][j] != 1){
            return;
        }
        a[i][j] = -1;
        bfs(i - 1, j, a);
        bfs(i, j - 1, a);
        bfs(i + 1, j, a);
        bfs(i, j + 1, a);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for(int i = 0 ; i < rows; i++){
            if(grid[i][0] == 1){
                bfs(i, 0, grid);
            }
            if(grid[i][cols - 1]){
                bfs(i, cols - 1, grid);
            }
        }
        for(int j = 0; j < cols; j++){
            if(grid[0][j] == 1){
                bfs(0, j, grid);
            }
            if(grid[rows - 1][j] == 1){
                bfs(rows - 1, j, grid);
            }
        }
        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};


class Solution {
// similar but bfs solution.
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q; 
        int n = grid.size(); 
        int m = grid[0].size(); 
        int vis[n][m] = {0}; 
        // traverse boundary elements
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // first row, first col, last row, last col 
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    // if it is a land then store it in queue
                    if(grid[i][j] == 1) {
                        q.push({i, j}); 
                        vis[i][j] = 1; 
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1}; 
        
        while(!q.empty()) {
            int row = q.front().first; 
            int col = q.front().second; 
            q.pop(); 
            
            // traverses all 4 directions
            for(int i = 0;i<4;i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i]; 
                // check for valid coordinates and for land cell
                if(nrow >=0 && nrow <n && ncol >=0 && ncol < m 
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1; 
                }
            }
            
        }
        
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // check for unvisited land cell
                if(grid[i][j] == 1 & vis[i][j] == 0) 
                    cnt++; 
            }
        }
        return cnt; 
    }
};

class Solution {
/*
this is a genius solution, we first find all the number of 1s , then we do a bfs on the edges,
and we count the 1s that was meant to be disabled by dfs, at the we subtract each other. 
*/
public:
    int dfs(int i,int j,vector<vector<int>> &A){
        if( i<0 || j<0 || i>=A.size() || j>=A[0].size() || A[i][j]==0)
            return 0;
        
        A[i][j] = 0;
        
        return 1+dfs(i-1,j,A)+dfs(i+1,j,A)+dfs(i,j-1,A)+dfs(i,j+1,A);
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        int all_one=0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++)
                    all_one+=A[i][j];
        }
        int close_one = 0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if((i==0 || j==0 || i==A.size()-1 || j==A[0].size()-1) && A[i][j]==1)
                    close_one+= dfs(i,j,A);
            }
        }
        return all_one - close_one;
    }
};
