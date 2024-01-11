class Solution {
// my intuitiion was right , use LCS and use Printing method, 
// but i was stuck on how to bring the missing letters in correct position.
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n = text1.size(); 
        int m = text2.size();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } 
                else if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string ans = "";
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(text1[i - 1] == text2[j - 1]){
                ans += text1[i - 1];
                i--;
                j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]){
                ans += text1[i - 1];
                i--;
            }
            else{
                ans += text2[j - 1];
                j--;
            }
        }
      // incase either i is incomplete or j is incomplete.
        while(i){
            ans += text1[i - 1]; i--;
        }
        while(j){
            ans += text2[j - 1]; j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
