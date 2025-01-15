class Solution {
public:
    int minimumLength(string s) {
        int count = 0;
        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        for (auto it: mp) {
            int f = it.second;
            count += (f % 2) ? f - 1: f - 2;
        } 

        return s.size() - count;
    }
};
