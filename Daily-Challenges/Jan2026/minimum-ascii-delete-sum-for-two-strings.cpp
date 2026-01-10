class Solution {
public:
    int kev(int i, int j, string a, string b) {
        if (i == a.size() || j == b.size()) return 0;

        if (a[i] == b[j]) {
            return a[i] + b[j] + kev(i+1, j+1, a, b);
        }

        return max(
            kev(i+1, j, a, b),
            kev(i, j+1, a, b)
        );
    }
    int minimumDeleteSum(string s1, string s2) {
        int sum = 0;

        for (int i = 0; i < s1.size(); i++) {
            sum += (int)(s1[i]);
        }
        for (int i = 0; i < s2.size(); i++) {
            sum += (int)(s2[i]);
        }

        int ans = kev(0, 0, s1, s2);

        return sum - ans;
    }
};

class Solution {
public:
    int kev(int i, int j, string a, string b, vector<vector<int>> &dp) {
        if (i == a.size() || j == b.size()) 
            return 0;

        if (dp[i][j] != -1) 
            return dp[i][j];

        if (a[i] == b[j]) {
            return dp[i][j] = a[i] + b[j] + kev(i+1, j+1, a, b, dp);
        }

        return dp[i][j] = max(
            kev(i+1, j, a, b, dp),
            kev(i, j+1, a, b, dp)
        );
    }
    int minimumDeleteSum(string s1, string s2) {
        int sum = 0;
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for (int i = 0; i < s1.size(); i++) {
            sum += (int)(s1[i]);
        }
        for (int i = 0; i < s2.size(); i++) {
            sum += (int)(s2[i]);
        }

        int ans = kev(0, 0, s1, s2, dp);

        return sum - ans;
    }
};

class Solution {
public:
    int kev(int i, int j, string a, string b, vector<vector<int>> &dp) {
        if (i == a.size() || j == b.size()) 
            return 0;

        if (dp[i][j] != -1) 
            return dp[i][j];

        if (a[i] == b[j]) {
            return dp[i][j] = a[i] + b[j] + kev(i+1, j+1, a, b, dp);
        }

        return dp[i][j] = max(
            kev(i+1, j, a, b, dp),
            kev(i, j+1, a, b, dp)
        );
    }
    int minimumDeleteSum(string s1, string s2) {
        int sum = 0;
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for (int i = 0; i < s1.size(); i++) {
            sum += (int)(s1[i]);
        }
        for (int i = 0; i < s2.size(); i++) {
            sum += (int)(s2[i]);
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = s1[i] + s2[j] + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return sum - dp[0][0];
    }
};
