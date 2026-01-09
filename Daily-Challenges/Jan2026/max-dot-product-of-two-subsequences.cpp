class Solution {
public:
    int kev(int i, int j, vector<int> a, vector<int> b) {
        if (i == a.size() || j == b.size())
            return -1e9;

        int case1 = (a[i] * b[j]) + max(0, kev(i+1, j+1, a, b));
        int case2 = kev(i+1, j, a, b);
        int case3 = kev(i, j+1, a, b);

        return max(max(case1, case2),case3);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        return kev(0, 0, nums1, nums2);
    }
};


class Solution {
public:
    int kev(int i, int j, vector<int> a, vector<int> b, vector<vector<int>> &dp) {
        if (i == a.size() || j == b.size())
            return -1e9;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int case1 = (a[i] * b[j]) + max(0, kev(i+1, j+1, a, b, dp));
        int case2 = kev(i+1, j, a, b, dp);
        int case3 = kev(i, j+1, a, b, dp);

        return dp[i][j] = max(max(case1, case2),case3);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return kev(0, 0, nums1, nums2, dp);
    }
};


class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for (int j = 0; j <= m; j++) {
            dp[n][j] = -1e9;
        }
         for (int i = 0; i <= n; i++) {
            dp[i][m] = -1e9;
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                int case1 = nums1[i] * nums2[j] + max(0, dp[i+1][j+1]);
                int case2 = dp[i+1][j];
                int case3 = dp[i][j+1];
                dp[i][j] = max(max(case1, case2),case3);
            }
        }

        return dp[0][0];
    }
};
