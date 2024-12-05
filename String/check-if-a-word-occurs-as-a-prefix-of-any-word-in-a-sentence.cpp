class Solution {
public:
    int isPrefixOfWord(string s, string sw) {
        int j = 0, p = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                j = 0;
                p++;
            }

            if ((i == 0 || (i-1 >= 0 && s[i-1] == ' ')) && s[i] == sw[j]) {
                while (i < s.size() && j < sw.size() && s[i] == sw[j]) {
                    i++;
                    j++;
                }

                if (j >= sw.size()) {
                    return p;
                }

                j = 0;
                i--;
            }
        }

        return -1;
    }
};
