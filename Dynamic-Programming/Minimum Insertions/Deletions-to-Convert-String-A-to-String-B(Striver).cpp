https://www.codingninjas.com/studio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION

// idea was simplge, find the longest common subsequence b/w two string and then find the missing
// characters by subtracting the length of the string. do it for both.

int canYouMake(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>  (m+1, 0));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <=m ; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return (n - dp[n][m]) + (m - dp[n][m]);
}
