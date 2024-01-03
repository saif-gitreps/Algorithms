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

class Solution {
// the same concept as longest common subsequence, you take the string reverse it, then find the LCS between them original and reversed.
public:
    bool check(string s){
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
    int kev(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(i < 0 || j < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] =  1 + kev(i - 1, j - 1, s1, s2, dp);
        }
        return dp[i][j] = max(kev(i, j - 1, s1, s2, dp), kev(i - 1, j , s1, s2, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s.begin() , s.end());
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return kev(n-1, n-1, s, s2, dp);
    }
};


class Solution {
// similar solution to longest common subsequence.
public:
    int longestPalindromeSubseq(string text1) {
        vector<vector<int>> dp(text1.size()+1, vector<int> (text1.size()+1, 0));
        string text2 = text1;
        reverse(text1.begin(), text1.end());
        for(int i = 0 ; i <= text1.size() ; i ++){
            for(int j = 0 ; j <= text2.size() ; j ++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                else{
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j -  1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
