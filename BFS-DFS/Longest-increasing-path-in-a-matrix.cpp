class Solution {
// Got MLE but it works. need to find a better way.
public:
    int bfs(int i, int j, vector<vector<int>> matrix){
        queue<pair<int, int>> q;
        int seq[] = {0, 1, 0, -1, 0};
        q.push({i, j});

        int count = 0;
        while(q.empty() != true){
            int n = q.size();
            
            for(int i = 0; i < n; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                int num = matrix[row][col];
                
                for(int j = 0; j < 4; j++){
                    int r = row + seq[j];
                    int c = col + seq[j + 1];
                    if(r >= 0 && c >= 0 && c < matrix[0].size()
                    && r < matrix.size() && matrix[r][c] > num){
                        q.push({r , c});
                    }
                }
            }
            count++;
        }
        return count;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mx = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mx = max(mx, bfs(i, j, matrix));
            }
        }
        return mx;
    }
};
