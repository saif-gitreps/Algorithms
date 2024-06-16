class Solution {
// not working idk why shitty problem.
public:
    void dfs(int src, bool &atlantic, bool &pacific,int r, int c,const vector<vector<int>> h){ 
        if((r + 1 >= h.size() && c - 1 < 0) || (r - 1 < 0 && c + 1 >= h[0].size())){
            atlantic = true;
            pacific = true;
            return;
        }
        if(r - 1 < 0 || c - 1 < 0){
            pacific = true;
        }
        if(r + 1 >= h.size() || c + 1 >= h[0].size()){
            atlantic = true;
        }
        if(r < 0 || c < 0 || c == h[0].size() || r == h.size()){
            return;
        }

        if(r + 1 < h.size() && h[r + 1][c] <= src) 
            dfs(h[r + 1][c], atlantic, pacific, r + 1, c, h);
        if(r - 1 >= 0 && h[r - 1][c] <= src)    
            dfs(h[r - 1][c], atlantic, pacific, r - 1, c, h);
        if(c + 1 < h[0].size() && h[r][c + 1] <= src)
            dfs(h[r][c + 1], atlantic, pacific, r, c + 1, h);
        if(c - 1 >= 0 && h[r][c - 1] <= src)
            dfs(h[r][c - 1], atlantic, pacific, r, c - 1, h);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                bool atlantic = false, pacific = false;
                dfs(heights[i][j], atlantic, pacific, i, j, heights);
                if(atlantic && pacific){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};

class Solution {
// So for my attempt even tho this shows TLE, The missing piece was that i didn't have a vis array. 
public:
    void dfs(int src, bool &atlantic, bool &pacific,int r, int c,const vector<vector<int>> h, map<pair<int, int> , bool> vis){ 
        if(r - 1 < 0 || c - 1 < 0){
            pacific = true;
        }
        if(r + 1 >= h.size() || c + 1 >= h[0].size()){
            atlantic = true;
        }
        if(r < 0 || c < 0 || c == h[0].size() || r == h.size()){
            return;
        }

        vis[{r, c}] = true;

        if(r + 1 < h.size() && !vis[{r + 1, c}] && h[r + 1][c] <= src) 
            dfs(h[r + 1][c], atlantic, pacific, r + 1, c, h, vis);
        
        if(r - 1 >= 0 && !vis[{r - 1, c}] && h[r - 1][c] <= src)    
            dfs(h[r - 1][c], atlantic, pacific, r - 1, c, h, vis);
        
        if(c + 1 < h[0].size() && !vis[{r , c + 1}] && h[r][c + 1] <= src)
            dfs(h[r][c + 1], atlantic, pacific, r, c + 1, h, vis);
        
        if(c - 1 >= 0 && !vis[{r , c - 1}] &&  h[r][c - 1] <= src)
            dfs(h[r][c - 1], atlantic, pacific, r, c - 1, h, vis);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        
        map<pair<int, int> , bool> vis;
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                bool atlantic = false, pacific = false;
                dfs(heights[i][j], atlantic, pacific, i, j, heights, vis);
                if(atlantic && pacific){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};


class Solution {
/*
    Cells on the border (first/last row, and first/last column) are guaranteed to get into the ocean. 
    You start off with the border cells and go from there to explore the inner land.

    The point here, I think, is that we do not need to scan the entire matrix to find the "start point" of DFS, 
    we just need to look at the first and last rows and columns. 
    Because essentially we can find all points from where water can get to the ocean
    by starting DFS at the border, and accepting the common point as answer.
*/
public:
    vector<int> offset = {0, 1, 0, -1, 0};

    bool outOfBounds(int row, int col, int m, int n){
        return row < 0 || col < 0 || row > m -1 || col > n -1;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j) {
        // m is for row and n is for col.
        int m = matrix.size();
        int n = matrix[0].size();

        visited[i][j] = true;
        for (int k =1 ; k<offset.size(); k++){
            int row = i + offset[k], col = j + offset[k-1] ;
            if( !outOfBounds(row, col, m, n) && !visited[row][col] && matrix[row][col] >= matrix[i][j])
                    dfs(matrix, visited, row, col);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pacific(n, vector<int> (m, 0));
        vector<vector<int>> atlantic(n, vector<int> (m, 0));
        // here n is row and m is for col.
        for(int i = 0; i < n; i++ ){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m - 1);
        }

        for(int j = 0; j < m; j++){
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, n - 1, j);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(atlantic[i][j] && pacific[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};
