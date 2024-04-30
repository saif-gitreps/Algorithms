class Solution {
// intuition was, that it is the same as the Longest common subsequence but instead, we are dealing with ASCIS.
// Here this sol showed MLE.
public:
    vector<vector<int>> dp;
    int kev(int i, int j, string s1, string s2){
        if(i <0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return s1[i] + kev(i - 1, j - 1, s1, s2);
        }

        return dp[i][j] = max(
            kev(i - 1, j, s1, s2), 
            kev(i, j - 1, s1 , s2)
        );
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(); int m = s2.size();

        dp.resize(n, vector<int> (m, -1));
        
        int res = kev(n - 1, m - 1, s1, s2);

        int total1 = 0, total2 = 0;
        for(auto s : s1){
            total1 += s;
        }
        for(auto s : s2){
            total2 += s;
        }

        return (total1 - res) + (total2 - res);
    }
};


class Solution {
// Successfully turned the solution into top-down tabulation, which worked.
public:
    vector<vector<int>> dp;
    
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(); int m = s2.size();

        dp.resize(n + 1, vector<int> (m + 1, -1));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j <= m; j++){
            dp[0][j] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
                }
            }
        }

        int total1 = 0, total2 = 0;
        for(auto s : s1){
            total1 += s;
        }
        for(auto s : s2){
            total2 += s;
        }

        return (total1 - dp[n][m]) + (total2 - dp[n][m]);
    }
};
