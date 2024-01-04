class Solution {
/*
  So the problem is with using the same longest common subtring algorithm , the edge case "aacabdkacaa" ,
  Here we are getting aaca as the lcs where it is not a palindrome but since we are using LCS alg , ans is aaca,
  The longest common subsequence algorithm worked for the LPSubsequence.
*/
public:
    string longestPalindrome(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        int mx = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                if(s2[i - 1] == s[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    mx = max(mx, dp[i][j]);
                }
            }
        }
        string ans = "";
        for(int i = 0 ;i < mx; i ++){
            ans += "$";
        }
        int i = n, j = n;
        while(i > 0 && j > 0){
            if(s2[i - 1] == s[j - 1] && dp[i][j] == mx){
                while(s2[i - 1] == s[j - 1]){
                    ans[mx - 1] = s2[i - 1];
                    mx --;
                    i --;
                    j --;
                }
                break;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]){
                i--;
            }
            else{
                j--;
            }
        } 
        return ans;
    }
};
