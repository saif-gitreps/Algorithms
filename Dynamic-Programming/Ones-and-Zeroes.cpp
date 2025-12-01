class Solution {
// works.
public:
    int findMaxForm(vector<string>& a, int m, int n) {
        int sz = a.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        
        for (int i = sz-1; i >= 0; i--) {
            int ones = 0, zeroes = 0;
            for (auto c : a[i]) {
                if (c == '0') zeroes++;
                if (c == '1') ones++;
            }
            for (int j = m; j >= zeroes; j--) {
                for (int k = n; k >= ones; k--) {
                    dp[j][k] =  max(
                        dp[j][k],
                        1 + dp[j-zeroes][k-ones]
                    );
                }
            }
        }

        return dp[m][n];
    }
};


class Solution {
// top down works too
public:
    int findMaxForm(vector<string>& a, int m, int n) {
        int sz = a.size();
        vector<vector<vector<int>>> dp(sz+1, 
            vector<vector<int>> (m+1, 
                vector<int> (n+1, 0)));

        dp[sz][m][n] = 0;
        
        for (int i = sz-1; i >= 0; i--) {
            int ones = 0, zeroes = 0;
            for (auto c : a[i]) {
                if (c == '0') zeroes++;
                if (c == '1') ones++;
            }
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j - zeroes < 0 || k - ones < 0) {
                        dp[i][j][k] = dp[i+1][j][k];
                    } else {
                        dp[i][j][k] =  max(
                            dp[i+1][j][k],
                            1 + dp[i+1][j-zeroes][k-ones]
                        );
                    }
                }
            }
        }

        return dp[0][m][n];
    }
};

class Solution {
// space optimized, works too
public:
    int findMaxForm(vector<string>& a, int m, int n) {
        int sz = a.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        
        for (int i = sz-1; i >= 0; i--) {
            int ones = 0, zeroes = 0;
            for (auto c : a[i]) {
                if (c == '0') zeroes++;
                if (c == '1') ones++;
            }
            for (int j = m; j >= zeroes; j--) {
                for (int k = n; k >= ones; k--) {
                    dp[j][k] =  max(
                        dp[j][k],
                        1 + dp[j-zeroes][k-ones]
                    );
                }
            }
        }

        return dp[m][n];
    }
};
