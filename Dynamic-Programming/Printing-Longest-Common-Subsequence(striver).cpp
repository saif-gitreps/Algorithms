class Solution {
// so here we are basically using the dp table to find the missing string that is the longest string
// https://www.youtube.com/watch?v=-zI4mrF2Pb4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=27
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = max(text1.size(), text2.size());
        
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, 0));
        
        for(int i = 0 ; i <= text1.size() ; i ++){
            for(int j = 0 ; j <= text2.size() ; j ++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                else{
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j -  1]);
                }
            }
        }
        int len =  dp[text1.size()][text2.size()];
        string ans = "";
        for(int i = 0 ; i < len; i++){
            ans += "$";
        }
        int i = text1.size(); int j = text2.size();
        while(i > 0 && j > 0){
            if(text1[i - 1] == text2[j - 1]){
                ans[len - 1] = text1[i - 1];
                len--;
                i--;
                j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]){
                i--;
            }
            else{
                j--;
            }
        }
        cout << ans << "\n";
        return len;
    }
};
int
