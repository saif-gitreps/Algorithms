class Solution {
// naive bruteforce approach , gets TLE.
public:
    int numSplits(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            unordered_set<char> s1;
            unordered_set<char> s2;
            for(int j = 0; j <= i; j++){
                s1.insert(s[j]);
            }
            for(int j = i+1; j < s.size(); j++){
                s2.insert(s[j]);
            }
            if(s1.size() == s2.size()){
                count++;
            }
        }
        return count; 
    }
};
