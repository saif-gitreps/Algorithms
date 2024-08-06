class Solution {
// Worked but i am struggling to convert it into a Bottom-Up tabulation.
public:
    int kev(int i, int curr, vector<int> &a, vector<vector<int>> &dp) {
        if (i == a.size()) return 0;
        if (dp[i][curr] != -1) return dp[i][curr];

        int ans = INT_MAX;
        if (i + 1 < a.size() && curr == a[i + 1]) {
            for (int k = 1; k <= 3; k++) {
                if (k != curr && a[i] != k)
                    ans = min(ans, 1 + kev(i, k, a, dp));
            }
        } else {
            ans = kev(i + 1, curr, a, dp);
        }

        return dp[i][curr] = ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(obstacles.size(), vector<int> (4, -1));
        return kev(0, 2, obstacles, dp);
    }
};


class Solution {
// Tabulation. 
public:
    int minSideJumps(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, INT_MAX));

        for (int i = 0; i <= 3; i ++) {
            dp[n][i] = 0; 
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= 3; j++) {
                if (i + 1 < n && j == a[i + 1]) {
                    for (int k = 1; k <= 3; k++) {
                        if (k != j && a[i] != k)
                            // so the thing that was giving me overflow was that i + 1.
                            // Now the thing is we are building the bottom-up, so in that case
                            // during the build up some of the cells of tabulation are INFITE(INT_MAX)
                            // now in recursion's bottom up this cell would have been filled up, but because of
                            // tabulation, this isnt, so we are taking the i + 1 of it. thats the best explanation I have.
                            
                            dp[i][j] = min(dp[i][j], 1 + dp[i+1][k]);
                    }
                }
                else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }

        return min({dp[0][1] + 1, dp[0][2] ,dp[0][3] + 1});
        // return dp[0][2];
    }
};

class Solution {
// space optimized, i need to start considering space optimization techniques now, it looks efficient.
public:
    int minSideJumps(vector<int>& a) {
        int n = a.size();
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);

        for (int i = 0; i <= 3; i ++) {
            next[i] = 0; 
        }

        for (int i = n - 1; i >= 0; i--) {
            curr.assign(4, INT_MAX);
            
            for (int j = 1; j <= 3; j++) {
                if (i + 1 < n && j == a[i + 1]) {
                    for (int k = 1; k <= 3; k++) {
                        if (k != j && a[i] != k)
                            curr[j] = min(curr[j], 1 + next[k]);
                    }
                }
                else {
                    curr[j] = next[j];
                }
            }
            for (int p = 0; p <= 3; p ++) {
                next[p] = curr[p]; 
            }
        }

        return min(min(next[1] + 1, next[2]), next[3] + 1);
    }
};
