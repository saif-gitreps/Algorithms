class Solution {
// working solution. try to simulate it on theory.
public:
    bool kev(int i, string s, set<string> st, vector<int> &dp){
        if(i == s.size()){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        string sub = "";
        for(int j = i; j < s.size(); j++){
            bool exists = kev(j + 1, s, st, dp);
            sub += s[j];
            if(st.count(sub) and exists){
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& w) {
        set<string> st;
        for(auto word: w){
            st.insert(word);
        }
        vector<int> dp(s.size(), -1);
        return kev(0, s, st, dp);
    }
};


class Solution {
// raw attempt, only worked for 28/45 cases.
// but i mean the concept is kind of very close right.
public:
    bool kev(int i, string s, vector<string> &w){
        // if(i > s.size()){
        //     return false;
        // }
        if(i >= s.size()){
            return false;
        }
        bool ans = false;

        for(int j = i + 1; j < s.size(); j++){
            vector<string>::iterator it = find(
                w.begin(), w.end(), s.substr(i, j)
            );

            if(it != w.end()){
                if(j == s.size() - 1){
                    return true;
                }
                ans = kev(j , s, w);
            }
        }
      
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return kev(0, s, wordDict);   
    }
};
