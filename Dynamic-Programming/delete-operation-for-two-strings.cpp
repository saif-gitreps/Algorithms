class Solution {
// EASY, just used the LCS algorithm and do some lil math.
public:
    int minDistance(string text1, string text2) {
        // if(text1 == text2) {
        //     return 0;
        // }

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
        int lcs = dp[text1.size()][text2.size()]; 
        return (text1.size() - lcs) + (text2.size() - lcs);

    }
};
