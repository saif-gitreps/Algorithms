class Solution {
// Recursive approach, idk how this one didnt show TLE OR MLE.
public:
    bool kev(int i, int j, string s, string t){
        if(i == s.size()){
            return true;
        }
        if(j >= t.size() || i > s.size()){
            return false;
        }
        if(s[i] == t[j]){
            return kev(i + 1, j + 1, s, t);
        }
        else{
            return kev(i, j + 1, s, t);
        }
    }
    bool isSubsequence(string s, string t) {
        return kev(0, 0, s, t);
    }
};

class Solution {
// Recursive appraoch was stupid anyway. This is much bettah.
public:
    bool isSubsequence(string s, string t) {
        int ans = 0, j = 0;
        for(int i = 0; i < t.size() && j < s.size(); i++){
            if(s[j] == t[i]){
                j++;
            }
        }
        if(j == s.size()){
            return true;
        }
        return false;
    }
};

