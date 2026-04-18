class Solution {
public:
    int mirrorDistance(int n) {
        long long rev_num = 0;
        int num = n;
       while (n > 0) {
            rev_num = ((rev_num * 10) + (n % 10));
            n /= 10;
        }

        return abs(num - rev_num);
    }
};
