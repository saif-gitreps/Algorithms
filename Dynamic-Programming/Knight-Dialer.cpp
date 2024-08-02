class Solution {
// This works but its TLE even for the first few cases. This is the bruteforce.
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

class Solution:
// apparently this soluton works for python and java.
    def __init__(self):
        self.mod = int(1e9 + 7)
        self.offset = [
            [1, 2], [-1, 2], [1, -2], [-1, -2], [2, 1], [-2, 1], [2, -1], [-2, -1]
        ]
        self.dp = []

    def isValid(self, i, j):
        if i < 0 or j < 0 or j >= 3 or i >= 4 or (i == 3 and j != 1):
            return False
        return True

    def kev(self, i, j, n):
        if n == 1:
            return 1

        if self.dp[n][i][j] != -1:
            return self.dp[n][i][j]

        ans = 0

        for o in self.offset:
            r = i + o[0]
            c = j + o[1]
            if self.isValid(r, c):
                ans = (ans + self.kev(r, c, n - 1)) % self.mod

        self.dp[n][i][j] = ans
        return ans
        
    def knightDialer(self, n: int) -> int:
        ans = 0
        self.dp = [[[-1 for _ in range(3)] for _ in range(4)] for _ in range(n + 1)]

        for i in range(4):
            for j in range(3):
                if not ((i == 3 and j == 0) or (i == 3 and j == 2)):
                    ans = (ans + self.kev(i, j, n)) % self.mod

        return ans


class Solution {
/* 
    We know that for n == 1 , its 10 anyway.
    I mean i understood the solution , what the intuition was.
    hers explaination vid: https://www.youtube.com/watch?v=wRF40TQUpxg
*/
public:
    const int mod = 1e9 + 7;
    int knightDialer(int n) {
        if (n == 1) return 10;

        int ans = 0;
        vector<int> dp(10, 1);
        unordered_map<int, vector<int>> mp;
        mp[0] = {4, 6};
        mp[1] = {6, 8};
        mp[2] = {7, 9};
        mp[3] = {4, 8};
        mp[4] = {3, 0, 9};
        mp[6] = {0, 1, 7};
        mp[7] = {2, 6};
        mp[8] = {1, 3};
        mp[9] = {2, 4};

        for (int i = 2; i <= n; i++) {
            vector<int> temp(10, 0);
            for (auto [key, arr] : mp) {
                for (auto numb : arr) {
                    temp[key] = (temp[key] + dp[numb]) % mod;
                }
            }
            dp = temp;
        }

        for (auto num : dp) {
            ans = (ans + num) % mod;
        }

        return ans;
    }
};
        
