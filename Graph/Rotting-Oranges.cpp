class Solution {
public:
    int bfs(queue<pair<int, int>> &q, vector<vector<int>> &grid, int &orange){
        int count = 0;
        int seq[] = {0 , 1, 0, -1, 0};

        while(q.empty() == false){
            int n = q.size();

            for(int i = 0; i < n; i++){
                int row = q.front().first;
                int col = q.front().second;

                q.pop();
                for(int i = 0; i < 4; i ++){
                    int r = row + seq[i];
                    int c = col + seq[i + 1];
                    if(r >= 0 && r < grid.size()
                    && c >= 0 && c < grid[0].size()
                    && grid[r][c] == 1){
                        grid[r][c] = 2;
                        q.push({r , c});
                        orange--;
                    }
                }
            }
            count++;
        }
        return count;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int orange = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair <int, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1){
                    orange ++;
                }
            }
        }
        if(orange == 0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }
        int ans = bfs(q, grid, orange);
        if(!orange){
            return ans - 1;
        }
        else{
            return -1;
        }
    }
};
