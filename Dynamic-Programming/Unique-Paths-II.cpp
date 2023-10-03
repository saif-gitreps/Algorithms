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
