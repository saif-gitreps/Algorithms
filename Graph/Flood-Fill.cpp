class Solution {
// same concept as Number of Island but we dont visit all the nodes but instead we have a fixed starting point.
public:
    void dfs(int row, int col, vector<vector<int>> &img, int originalColor, int replaceColor){
        if(row < 0 || row >= img.size() 
        || col < 0 || col >= img[0].size() 
        || img[row][col] != originalColor
        || img[row][col] == replaceColor){
            return;
        }
        img[row][col] = replaceColor;
        dfs(row - 1, col, img, originalColor, replaceColor);
        dfs(row + 1, col, img, originalColor, replaceColor);
        dfs(row, col - 1, img, originalColor, replaceColor);
        dfs(row, col + 1, img, originalColor, replaceColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(sr , sc, image, image[sr][sc], color);

        return image;       
    }
};

class Solution {
// bfs solutions works as well.
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origColor = image[sr][sc];
        queue<pair<int, int>> q;

        q.push({sr, sc});
        image[sr][sc] = color;

        vector<int> seq = {0 , 1, 0, -1, 0};

        while (q.empty() != true){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++){
                int r = row + seq[i];
                int c = col + seq[i + 1];
                if (r >= 0 && r < image.size() 
                && c >=0 && c < image[0].size()
                && image[r][c] == origColor
                && image[r][c] != color){
                    q.push({r, c});
                    image[r][c] = color;
                }
            }
        }
        return image;       
    }
};
