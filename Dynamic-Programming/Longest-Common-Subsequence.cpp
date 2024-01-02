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
