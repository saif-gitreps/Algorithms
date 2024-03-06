class Solution {
// TLE but hey something must work.
public:
    bool bfs(int row, int col,int n, int m, vector<vector<int>> a){
        if(row < 0 || col < 0 || row >= n || col >= m || a[row][col]){
            return false;
        }
        a[row][col] = 1;
        if(row == n - 1){
            return true;
        }
        
        int ans = (
            bfs(row + 1, col, n, m, a) ||
            bfs(row - 1, col, n, m, a) ||
            bfs(row, col + 1, n, m, a) || 
            bfs(row, col - 1, n, m, a) 
        );
        
        return ans;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int count = 0;
        int mx = 0;
        vector<vector<int>> a(row + 1 , vector<int> (col + 1, 0));

        for(int i = 0; i < cells.size(); i++){
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;

            a[r][c] = 1;
            count++;
            
            for(int j = 0; j < col; j++){
                if(!a[0][j] && bfs(0, j, row, col, a)){
                    mx = max(count, mx);
                }
            }

        }

        return mx;

    }
};
