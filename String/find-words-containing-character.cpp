class Solution {
// fails for half of the cases.
// fix: minor error, most of the sol are N^2 anyway
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (words[i][j] == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
