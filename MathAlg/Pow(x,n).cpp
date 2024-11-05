class Solution {
public:
    double myPow(double x, int n) {
        long long N = n < 0 ? (long long)-1 * n : n;
        double ans = 1;

        while(N > 0) {
            if (N % 2 == 1) {
                ans *= x;
                N--;
            } else {
                x *= x;
                N /= 2;
            }
        }

        return n < 0 ? 1.0 / ans : ans;
    }
};
