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

class Solution {
// two arrays to store unique points from both sides.
// Why compare pref[i] and suff[i +1]
// The reason being when you created pref[i], at each index you stored unique occurrence until that index. 
// But, when you created suff[i], you stored unique occurrence until i at i + 1. And, when you are splitting at i, 
// you need to compare unique occurrences from 0 to i and i + 1 to string length.
// Dry run "aacaba" and rereaad to understand.
public:
    int numSplits(string s) {
        int count = 0;
        unordered_map<char,int> mp;
        vector<int> pref(s.size());
        vector<int> suff(s.size());
        // using set means additional logn complexity, map is constant time.
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            pref[i] = mp.size(); 
        }
        mp.clear();
        for(int i = s.size()-1; i >= 0; i--){
            mp[s[i]]++;
            suff[i] = mp.size();
        }
        for(int i = 1; i < s.size(); i++){
            if(pref[i-1] == suff[i]){
                count++;
            }
        }
        return count; 
    }
};
