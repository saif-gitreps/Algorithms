class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto w: strs) {
            string word = w;
            sort(word.begin(), word.end());
            mp[word].push_back(w);
        }
        vector<vector<string>> ans;

        for (auto it : mp) {
            
        }
    }
};
