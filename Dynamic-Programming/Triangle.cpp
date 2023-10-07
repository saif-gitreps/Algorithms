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


class Solution {
// so my missing concept was that we could either go down or one diagonal. 
// and other missing step was we had to write n-1 and j condition which i didnt.
public:
    int kev(int i,int j, vector<vector<int>> &a, vector<vector<int>> &dp){
        if(i == a.size() -1 ){
            return dp[i][j] = a[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int fs = INT_MAX;
        int ss = INT_MAX;
        fs = a[i][j] + kev(i+1, j, a, dp);
        ss = a[i][j] + kev(i+1, j+1, a, dp);
        return dp[i][j] = min(fs, ss);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n , vector<int> (m, -1));
        return kev(0, 0, triangle, dp);
    }
};


class Solution {
// tabulation rule of thumb , if your recurrence was top-down , then your tabluation will be bottom-up. rest is copy paste.
public:
    int kev(int i,int j, vector<vector<int>> &a, vector<vector<int>> &dp){
        if(i == a.size() -1 ){
            return dp[i][j] = a[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int fs = INT_MAX;
        int ss = INT_MAX;
        fs = a[i][j] + kev(i+1, j, a, dp);
        ss = a[i][j] + kev(i+1, j+1, a, dp);
        return dp[i][j] = min(fs, ss);
    }
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[n - 1].size();
        vector<vector<int>> dp(n , vector<int> (n, -1));
        for(int j = 0 ; j < n ; j ++){
            dp[n-1][j] = a[n-1][j];
        }
        for(int i = n-2 ; i >= 0; i--){
            for(int j = i; j >= 0 ; j--){
                // now jus copy paste my kev.
                int fs = INT_MAX;
                int ss = INT_MAX;
                fs = a[i][j] + dp[i+1][j];
                ss = a[i][j] + dp[i+1][j+1];
                dp[i][j] = min(fs , ss);
            }
        }
        return dp[0][0];
    }
};
