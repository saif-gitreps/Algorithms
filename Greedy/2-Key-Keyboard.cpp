class Solution {
// best attempt with DP. 31/126 cases.
public:
    int kev(int n, int screen, int clipboard, bool canCopy, vector<vector<int>> &dp){
        if(screen == n){
            return 0;
        }
        if(screen > n){
            return 0;
        }
        if(dp[screen][clipboard] != -1){
            return dp[screen][clipboard];
        }
        int copy = INT_MAX, paste = INT_MAX;
        if(canCopy){
            copy = 1 + kev(n, screen, screen, 0, dp);
        }
        if(clipboard > 0){
            paste = 1 + kev(n, screen + clipboard, clipboard, 1, dp);
        }
        return dp[screen][clipboard] = min(copy , paste);
    }
    int minSteps(int n) {
        if(n == 1) {
            return 0;
        }
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return kev(n, 1, 0, 1, dp);    
    }

};

