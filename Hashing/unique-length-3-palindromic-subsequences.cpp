class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int cnt = 0;
        vector<int> first(26, INT_MAX);
        vector<int> last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            first[s[i]-'a'] = min(i, first[s[i] - 'a']); // min because we want the left most first index of that char to get the most no. of palindrome.
            last[s[i]-'a'] = i; // making sure we get the right most
        }

        // we will try to find the most unique number middle elements between the chars, this makes sense if you understand the probelm.
        for (int i = 0; i < 26; i++) {
            unordered_set<int> st;
            int l = first[i];
            int r = last[i];
            if (l == INT_MAX) continue;
            
            for (int j = l+1; j < s.size() && j < r; j++) {
                if (st.find(s[j] - 'a') == st.end()) 
                    st.insert(s[j] - 'a');
            }
            cnt += st.size();
        }

        return cnt;
    }
};
