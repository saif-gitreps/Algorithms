class Solution {
// This is the raw recursive call.
public:
    void kev(int row,int col, int &ans, vector<vector<int>>& og){
        if(row == 0 && col == 0){
            if(og[row][col] == 1){
                return;
            }
            ans++;
            return;
        }
        if(row < 0 || col < 0){
            return;
        }
        if(og[row][col] == 1){
            return;
        }
        kev(row -1, col, ans, og);
        kev(row, col-1 , ans, og);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int row = og.size();
        int col = og[0].size();
        int ans =0;
        kev(row-1 , col-1 ,ans, og);
        return ans;
    }
};


class Solution {
// Top - down appraoch worked .
public:
    int kev(int row,int col, vector<vector<int>>& og, vector<vector<int>>&dp){
        if(row == 0 && col == 0){
            if(og[row][col] == 1){
                return dp[row][col] = 0;
            }
            return dp[row][col] = 1;
            
        }
        if(row < 0 || col < 0){
            return 0;
        }
        if(og[row][col] == 1){
            return dp[row][col] = 0;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int up = 0,left = 0;
        up = kev(row -1, col, og, dp);
        left = kev(row, col-1, og, dp) ;
        return dp[row][col] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int row = og.size();
        int col = og[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        kev(row-1 , col-1 , og ,dp);
        return dp[row-1][col-1];
    }
};

class Solution {
// tab method worked
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
    int row = og.size();
    int col = og[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (og[i][j] == 1) {
                dp[i][j] = 0;
            } 
            else if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } 
            else {
                int up = 0, left = 0;
                if (i >= 1) {
                    up = dp[i - 1][j];
                }
                if (j >= 1) {
                    left = dp[i][j - 1];
                }
                dp[i][j] = up + left;
            }
        }
    }
    return dp[row-1][col-1];
    }
};
