class Solution {
// kind of worked till 17 cases.
public:
    int kev(int i,int j, vector<vector<int>> &a, vector<vector<int>> &dp){
        // if(i == a.size()-1){
        //     return dp[i][j] = a[i][j];
        // }
        if(i == a.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int sum = 0;
        int mn = 1000005;
        for(int k = j; k < a[i].size(); k++){
            sum = a[i][k] + kev(i + 1, k, a, dp);
            mn = min(mn, sum);
        }
        return dp[i][j] = mn;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[ n - 1 ].size();
        vector<vector<int>> dp(n , vector<int> (m, -1));
        return kev(0, 0, triangle, dp);
    }
};
