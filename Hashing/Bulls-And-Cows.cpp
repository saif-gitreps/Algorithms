class Solution {
// attempt 1 : passed 89/160 cases.
public:
    string getHint(string s, string g) {
        int cows = 0;
        int bulls = 0;
        unordered_map<int,char> mp1;
        unordered_map<char,int> mp2;
        for(int i = 0; i < s.size(); i++){
            mp1[i] = s[i];
            mp2[s[i]]++;
        }
        for(int i = 0 ; i < g.size(); i++){
            if(mp2[g[i]] >= 1){
                if(mp1[i] == g[i]){
                    bulls++;
                }
                else{
                    cows++;
                }
                mp2[g[i]]--;
            } 
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";

    }
};
