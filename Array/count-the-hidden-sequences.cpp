    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long a = 0, ma = 0, mi = 0;
        for (int d: diff) {
            a += d;
            ma = max(ma, a);
            mi = min(mi, a);
        }
        return max(0L, (upper - lower) - (ma - mi) + 1);
    }


// OJ: https://leetcode.com/contest/biweekly-contest-70/problems/count-the-hidden-sequences/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfArrays(vector<int>& A, int lower, int upper) {
        long sum = 0, mn = 0, mx = 0;
        for (int n : A) {
            sum += n;
            mn = min(mn, sum);
            mx = max(mx, sum);
        }
        return max(0L, mn - mx + upper - lower + 1);
    }
};
