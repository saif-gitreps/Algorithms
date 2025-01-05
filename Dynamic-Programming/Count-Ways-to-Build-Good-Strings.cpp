class Solution {
// here we didnt need to use string at all, like i am not checking the condition of the string just length.
public:
    int kev(string s, int low, int high, string z, string o) {
        if (s.size() > high) {
            return 0;
        }

        int count = 0;

        if (s.size() >= low && s.size() <= high) {
            count = 1;
        }

        return count + kev(s + z, low, high, z, o) + kev(s + o, low, high, z, o);
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        string z = "";
        string o = "";
        for (int i = 0; i < zero; i++) z += "0";
        for (int i = 0; i < one; i++) o += "1";

        return kev("", low, high, z, o);
    }
};

class Solution {
// i was dumb, i should have just used integer as a combinator (the item used for making different rec combination)
// i used string which gave MLE.
public:
    unordered_map<int, int> dp;
    const int mod = 1e9 + 7;

    int kev(int t, int low, int high, int z, int o) {
        if (t > high) {
            return 0;
        }

        if (dp.find(t) != dp.end()){
            return dp[t];
        }

        int count = 0;

        if (t >= low && t <= high) {
            count = 1;
        }

        dp[t] = (count + 
                kev(t + z, low, high, z, o) + 
                kev(t + o, low, high, z, o)) % mod;

        return dp[t];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        return kev(0, low, high, zero, one);
    }
};
