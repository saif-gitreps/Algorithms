class Solution {
public:
    // const int mod = 1e9 + 7;
    long long kev(int i, vector<vector<int>> &a, vector<long long> &dp) {
        if (i >= a.size()) {
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        return dp[i] =  max(
            a[i][0] + kev(i + a[i][1] + 1, a, dp), 
            kev(i+1, a, dp)
        );
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return kev(0, questions, dp);
    }
};