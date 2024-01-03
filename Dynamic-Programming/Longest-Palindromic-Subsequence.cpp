class Solution {
// 40 / 80 passes.
public:
    bool check(string s){
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
    int kev(int i, string str, string s, vector<vector<int>> &dp){
        if(i == s.size()){
            if(check(str)){
                return str.size();
            } 
            else{
                return 0;
            }
        }
        if(dp[i][str.size()] != -1){
            return dp[i][str.size()];
        }
        str.push_back(s[i]);
        int pick = kev(i + 1, str, s, dp);
        str.pop_back();

        int not_pick = kev(i + 1, str, s, dp);

        return dp[i][str.size()] = max(pick ,not_pick); 
        
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), (vector<int> (s.size(), -1)));
        return kev(0, "", s, dp);
    }
};
