class Solution {
// worked for 46/48 cases and TLE
public:
    int distinctEchoSubstrings(string text) {
        //unordered_map<string, int> mp;
        unordered_set<string> mp;

        for(int i = 0; i < text.size(); i++){
            string str = "";
            for(int j = i; j < text.size(); j++){
                str += text[j];
                mp.insert(str);
            }
        }
        
        int count = 0;

        for(auto s : mp){
            if(mp.count(s + s)){
                count ++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int distinctEchoSubstrings(string s) {
        unordered_set<string> subs;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i;
                if (j + len <= n && s.compare(i, len, s, j, len) == 0) {
                    subs.insert(s.substr(i, len));
                }
            }
        }
        
        return subs.size();
    }
};
