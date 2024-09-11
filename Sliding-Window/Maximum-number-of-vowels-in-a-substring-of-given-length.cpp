class Solution {
//ez
public:
    bool isVowel(char a) {
        return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
    }
    int maxVowels(string s, int k) {
        int mx = 0;
        int count = 0;

        for (int i = 0, j = 0; j < s.size(); j++) {
            if (j - i + 1 > k) {
                if (isVowel(s[i])) count--;
                i++;
            }

            if (isVowel(s[j])) count++;

            mx = max(mx, count);
            if (mx == k) return mx;
        }

        return mx;
    }
};
