class Solution {
// naive attempt, i think i need to readjust the recursion a bit.
public:
    unordered_map<string,int> mp;    
    void kev(int n ,string str, string s){
        if(n < 0){
            mp[str]++;
            return;
        }
        str += s[n];
        kev(n - 1, str, s);
        str.pop_back();
        kev(n - 1, str, s);
    }
    int longestCommonSubsequence(string text1, string text2) {
        kev(text1.size() - 1, "", text1);
        kev(text2.size() - 1, "", text2);
        int mx = 0;
        for(auto p : mp){
            if(p.second >= 2){
                int size = p.first.size();
                mx = max(mx, size);
            }
        }
        return mx;
    }
};

class Solution {
// passes 46 / 47 cases and shows TLE , have to do tabulation.
// so the recursive approach is a bit new to me so this will take a while to get used to .
public:
    int kev(int i1, int i2, string s1, string s2, vector<vector<int>> &dp){
        if(i1 < 0 || i2 < 0){
            return 0;
        }
        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        }
        if(s1[i1] == s2[i2]){
            return 1 + kev(i1 - 1, i2 - 1, s1, s2, dp);
        }
        return dp[i1][i2] =  max(kev(i1 - 1, i2, s1, s2, dp), kev(i1, i2 - 1, s1 , s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = max(text1.size(), text2.size());
        //memset(dp, -1, sizeof(n));
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return kev(text1.size() - 1, text2.size() - 1, text1, text2, dp);
    }
};


class Solution {
// in the tabulation , we shift the numbers one digit to the right, so we made the dp array
// 1 indexed instead of 0 index, but we are checking in i - 1 and j - 1 for proper index mapping.
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = max(text1.size(), text2.size());
        
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, 0));
        
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

class Solution {
// kind of confused for the space optimized solution .
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = max(text1.size(), text2.size());
        
        //vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, 0));

        vector<int> prev(text2.size() + 1);
        vector<int> curr(text2.size() + 1);

        for(int i = 0 ; i <= text1.size() ; i ++){
            for(int j = 0 ; j <= text2.size() ; j ++){
                if(i == 0 || j == 0){
                    prev[j] = 0;
                }
                else if(text1[i - 1] == text2[j - 1]){
                    curr[j] = 1 + prev[j - 1];
                } 
                else{
                    curr[j] = max(curr[j - 1] , prev[j]);
                }
                prev = curr;
            }
        }
        return prev[text2.size()];

    }
};
