class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& g) {
        vector<int> ans;
        int max_len = 0;
        int fast = 1;

        for (int i = 0; fast < g.size();) {
            if (fast > i) {
                if (g[i] != g[fast]) {
                    ans.push_back(i);
                    ans.push_back(fast);
                    i = fast;
                }
                fast++;
            }
        } 

        vector<string> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < ans.size(); i++){ 
            if (mp.find(ans[i]) == mp.end()) {
                res.push_back(words[ans[i]]);
            }

            mp[ans[i]] = 1;
        }

        if (res.size() == 0) {
            return {words[0]};
        }

        return res;
    }
};
