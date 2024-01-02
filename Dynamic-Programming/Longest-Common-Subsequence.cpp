class Solution {
// naive attempt, i think i need to readjust the recursion a bit.
public:
    unordered_map<string,int> mp;    
    void kev(int n ,string str, string s){
        if(n < 0){
            mp[str]++;
            return;
        }
        str += s[n];
        kev(n - 1, str, s);
        str.pop_back();
        kev(n - 1, str, s);
    }
    int longestCommonSubsequence(string text1, string text2) {
        kev(text1.size() - 1, "", text1);
        kev(text2.size() - 1, "", text2);
        int mx = 0;
        for(auto p : mp){
            if(p.second >= 2){
                int size = p.first.size();
                mx = max(mx, size);
            }
        }
        return mx;
    }
};
