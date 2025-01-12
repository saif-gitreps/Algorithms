class Solution {
// bruteforce.
public:
    char shiftBackward(char c) {
        if (c == 'a') {
            return 'z';
        } else {
            return c - 1;
        }
    }
    char shiftForward(char c) {
        if (c == 'z') {
            return 'a';
        } else {
            return c + 1;
        }
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for (auto shift: shifts) {
            for (int i = shift[0]; i <= shift[1]; i++) {
                if (shift[2]) {
                    s[i] = shiftForward(s[i]);
                } else {
                    s[i] = shiftBackward(s[i]);
                }
            }
        }

        return s;
    }
};

class Solution {
public:
    int shift(int times) {
        times = times % 26;
        
        if (times < 0) 
            return 26 + times;
        
        return times;
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> pref(s.size()+1, 0);
        
        for (auto shift: shifts) {
            if (shift[2]) {
                pref[shift[0]] += 1;
                pref[shift[1] + 1] -= 1;
            } else {
                pref[shift[0]] -= 1;
                pref[shift[1] + 1] += 1;
            }
        }

        for (int i = 1; i < pref.size(); i++) {
            pref[i] = pref[i] + pref[i-1];
        }

        for (int i = 0; i < s.size(); i++) {
            /* take s[i] = b, and pref[i] = -2.
               (b - a = 1) + (25) = 26
               26 % 26 = 1 , 1 + a = b  
            */ 
            s[i] = ((s[i] - 'a') + shift(pref[i])) % 26 + 'a';
        }

        return s;
    }
};
