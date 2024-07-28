class Solution {
// This works but its TLE even for the first few cases. This is the actual bruteforce.
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> offset = {{1,2} , {-1,2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2,-1}, {-2, -1}};
    vector<vector<int>> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
    unordered_map<string, bool> dp;

    bool isValid(int i, int j) {
        if (i < 0 || j < 0 || j >= 3 || i >= 4 || m[i][j] == -1) {
            return false;
        }
        return true;
    }

    int kev(int i, int j, string num, int n) {
        if (n <= 0) {
            return 0;
        }
        if (dp.count(num)) return 0;

        dp[num + to_string(m[i][j])] = true;
        int ans = 1;

        for (auto o : offset) {
            int r = i + o[0];
            int c = j + o[1];
            if (isValid(r, c)) {
                ans += kev(r, c, num + to_string(m[r][c]), n - 1);
            }
        }

        return ans;
    }

    int knightDialer(int n) {
        int ans = 0;
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (m[i][j] != -1)
                    ans += (kev(i, j, "", n) % mod);
            }
        }

        return ans;
    }
};

class Solution {
// I mean this waas gonna give a TLE anyway but atleast it worked, and i wasnt far off the idea,
// my idea was close. The only mistake i did was that i return on n == 0, whereareas i should have just return on n == 1.

public:
    const int mod = 1e9 + 7;
    vector<vector<int>> offset = {
        {1,2} , {-1,2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2,-1}, {-2, -1}
    };
    vector<vector<vector<int>>> dp;

    bool isValid(int i, int j) {
        if (i < 0 || j < 0 || j >= 3 || i >= 4 || (i == 3 && j != 1)) {
            return false;
        }
        return true;
    }

    int kev(int i, int j, int n) {
        if (n == 1) {
            return 1;
        }

        if (dp[n][i][j] != -1) return dp[n][i][j];

        int ans = 0;

        for (auto o : offset) {
            int r = i + o[0];
            int c = j + o[1];
            if (isValid(r, c)) {
                ans = (ans + kev(r, c, n - 1)) % mod;
            }
        }

        return dp[n][i][j] = ans;
    }

    int knightDialer(int n) {
        int ans = 0;
        dp.resize(n + 1, vector<vector<int>> (4, vector<int> (3, -1)));
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (!((i == 3 && j == 0) || (i == 3 && j == 2)))
                    ans = (ans + kev(i, j, n)) % mod;
            }
        }

        return ans;
    }
};
