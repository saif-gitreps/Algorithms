class Solution {
// prolly the best recursive attempt i could come up with.
public:
    int kev(int i, int j,string s, string p, char wc){
        if(i == 0 && j == 0){
            if(s[i] == p[j] || p[j] == '?' || p[j] == '*'){
                return 1;
            }
            return 0;
        }
        if(i < 0){
            if(wc != '-1'){
                return 1;
            }
            return 0;
        }
        if(j < 0){
            if(i >= 0 && s[i] == wc){
                return kev(i - 1, j, s , p, wc);
            }
            else{
                wc = '-1';
                return 0;
            }
        }
        int ans = 0;
        if(s[i] == p[j]){
            ans += kev(i - 1, j - 1, s, p, wc);
        }
        else if(p[j] == '?'){
            ans += kev(i - 1, j - 1, s, p, wc);
        }
        else if(p[j] == '*'){
            wc = s[i];
            ans += kev(i - 1, j - 1, s, p, wc);
        }
        return ans;
    }
    bool isMatch(string s, string p) {
        return kev(s.size()-1, p.size()-1, s, p, '-1');
    }   
};


class Solution {
// This worked but shows MLE because of the stack space usage,
// So the doubt I had with * was, can it not go infinite when it is matching with space, 
// well it will only be accepted for empty strings if the rest of the P is *, else it won't.
// also we are brute-forcing the * case, one Kev will ignore the star, and the other will match the start and move forward.
// now in this case we won't be matching with the empty strings because The remaing of the P is not * only.
// The problem statement was vague AF, I didn't understand the problem properly.
public:
    int kev(int i, int j,string s, string p, vector<vector<int>> &dp){
        if(i < 0 && j < 0){
            return true;
        }
        if(j < 0 && i >= 0){
            return false;
        }
        if(i < 0 && j >= 0){
            for(int remaining = 0; remaining <= j; remaining++){
                if(p[remaining] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(s[i] == p[j] || p[j] == '?'){
            ans += kev(i - 1, j - 1, s, p, dp);
        }
        if(p[j] == '*'){
            // we either ignore the start and move forward, or we match the i char of S and continue.
            ans += kev(i - 1, j , s ,p ,dp) || kev(i , j - 1, s, p, dp);
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return kev(n - 1, m - 1, s,  p, dp);
    }  
};

class Solution {
// tab works.
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , -1));
        
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            dp[i][0] = false;
        }
        for(int j = 1; j <= m; j++){
            int check = true;
            for(int remaining = 1; remaining <= j; remaining++){
                if(p[remaining - 1] != '*'){
                    check = false; break;
                }
            }
            dp[0][j] = check;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int ans = 0;
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    ans += dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*'){
                    ans += (dp[i - 1][j] || dp[i][j - 1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][m];
    }  
};

class Solution {
// so called space optimzed sol.
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> curr(m + 1, false), prev(m + 1, false);
        prev[0] = true;
        for(int j = 1; j <= m; j++){
            int check = true;
            for(int remaining = 1; remaining <= j; remaining++){
                if(p[remaining - 1] != '*'){
                    check = false; break;
                }
            }
            prev[j] = check;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int ans = 0;
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    ans += prev[j - 1];
                }
                else if(p[j - 1] == '*'){
                    ans += (prev[j] || curr[j - 1]);
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        return prev[m];
    }  
};
