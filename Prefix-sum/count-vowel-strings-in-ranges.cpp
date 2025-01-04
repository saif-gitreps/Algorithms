class Solution {
// My logic was correct, the mistake was prefix calculation which led to complication.
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool is(string s) {
        return isVowel(s[0]) && isVowel(s.back());
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pref(words.size(), 0);
        
        for (int i = 0; i < words.size(); i++) {
            if (i == 0) {
                if (is(words[i])) 
                    pref[i] = 1;
            } else {
                pref[i] = pref[i-1] + (is(words[i]) ? 1 : 0);
            }
        }

        vector<int> ans;

        for (auto q : queries) {
            int left = q[0], right = q[1];
            if (left == 0) {
                ans.push_back(pref[right]); 
            } else {
                ans.push_back(pref[right] - pref[left - 1]); 
            }
        }

        return ans;
    }
};
