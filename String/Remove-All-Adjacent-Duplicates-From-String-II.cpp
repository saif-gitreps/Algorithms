class Solution {
// my intuition was correct. but my implementation is always complicated, i cant think of simple solutions.
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++;
                if (st.top().second == k) {
                    st.pop();
                }
            } else {
                st.push({c, 1});
            }
        }

        string ans = "";
        
        while (!st.empty()) {
            ans.append(st.top().second, st.top().first); 
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
