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
