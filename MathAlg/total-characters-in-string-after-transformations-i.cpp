class Solution {
public:
    const int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        while (t--) {
            string temp = "";
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 'z') {
                    temp += "ab";
                } else {
                    temp += (s[i] + 1);
                }
            }
            s = temp;
        }

        return s.size() % mod;
    }   
};
