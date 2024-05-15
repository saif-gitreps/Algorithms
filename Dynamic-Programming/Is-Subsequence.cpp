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

class Solution {
// Idea is we keep a map of all chars of T with an array of indexes on which those characters were encountered.
// Then we traverse every char of S. We check if the current Char doesnt exist then return false.
// Then we take the index array. We try to find the element based on the fact that
// lowerbound is used to keep the relative order of the subsequence.
// s = ace is subseq of t = abcde because a then c then e is in the relative order inside t.
// This helps us avoid the cases where a char may exist but it way behind , and it is not suitable character 
// because it does not maintain the relative ordering.
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < t.size();i ++){
            mp[t[i]].push_back(i);
        }

        int relative_order = 0;
        for(auto c : s) {
            if(mp.find(c) == mp.end()){
                return false;
            }
            vector<int> index_array = mp[c];
            auto it = lower_bound(index_array.begin(), index_array.end(), relative_order);
            if(it == index_array.end()) {
                return false;
            }
            relative_order = *it + 1;
        }
        return true;
    }
};

