class Solution {
// Easy , idk why mine worked without memo.
public:
    void kev(int i, string str, string s, unordered_set<string> st, vector<string> &ans) {
        if (i == s.size()) {
            if (str != "") {
                str.pop_back();
                ans.push_back(str);
            }
            return;
        };
        string temp = "";
        for (int k = i; k < s.size(); k++) {
            temp += s[k];
            if (st.find(temp) != st.end()){
                kev(k + 1, str + temp + " ", s, st, ans);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> st;

        for (auto word: wordDict) {
            st.insert(word);
        }

        kev(0, "", s, st, ans);

        return ans;
    }
};
