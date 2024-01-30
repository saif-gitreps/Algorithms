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


class Solution {
// had similar idead but the missing implementation was the prev one , how would i avoid conflict of the first 
// starting point because of <= condition. Like we have to ignore if the element is less than or equal to.
// we can avoid this first element issue by assigning it as -1.
// also we are memoizing matrix index of each element.
public:
    int dfs(int i, int j, vector<vector<int>> &matrix, int prev, map<pair<int,int> , int> &dp){
        if(i < 0 || j < 0 || i >= matrix.size() || 
        j >= matrix[0].size() ||
        matrix[i][j] <= prev){
            return 0;
        }
        if(dp.find({i, j}) != dp.end()){
            return dp[{i, j}];
        }
        int ans = 1;
        ans = max(ans, 1 + dfs(i + 1, j, matrix, matrix[i][j], dp));
        ans = max(ans, 1 + dfs(i - 1, j, matrix, matrix[i][j], dp));
        ans = max(ans, 1 + dfs(i, j + 1, matrix, matrix[i][j], dp));
        ans = max(ans, 1 + dfs(i, j - 1, matrix, matrix[i][j], dp));
        return dp[{i, j}] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mx = 1;
        map<pair<int, int>, int> dp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mx = max(mx, dfs(i, j, matrix, -1, dp));
            }
        }
        return mx;
    }
};
