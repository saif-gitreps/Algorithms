class Solution {
// weird problem
public:
    int const mx = 1e9;
    int kev(int i, int j, vector<vector<int>>& a, int n, int m) {
        if (i == n-1 && j == m-1) {
            return 0;
        }

        if (i == n || j == m) {
            return mx;
        }

        int val = 0;
        if (i == 0 && j == 0) {
            val = 0;
        } else {
            val = a[i][j];
        }

        return min(
            1 + val + kev(i+1, j, a, n, m),
            1 + val + kev(i, j+1, a, n, m)
        );
    }
    int minTimeToReach(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        return kev(0, 0, a, n, m);
    }
};
