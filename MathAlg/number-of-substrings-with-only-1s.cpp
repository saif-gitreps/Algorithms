class Solution {
// yay  i was able to solve it in 15 mins.
public:
    int numSub(string s) {
        long long count = 0, ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < s.size(); i++) {
            if (s[i]-'0' == 1) {
                while (i < s.size() && s[i] == '1') {
                    count++;
                    i++;
                }
                ans = (ans + (count * (count + 1)) / 2) % mod;
                count = 0;
            }
        }

        return (int)ans;
    }
};
