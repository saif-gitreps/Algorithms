class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int len = 0;
            unordered_map<char, bool> mp;
            for (int j = i; j < s.size(); j++) {
                if (mp[s[j]]) {
                    break;
                } else {
                    len++;
                    mp[s[j]] = 1;
                }
                ans = max(ans, len);
            }
        }

        return ans;
    }
};
