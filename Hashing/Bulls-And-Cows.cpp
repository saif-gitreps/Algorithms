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


class Solution {
public:
    string getHint(string s, string g) {
        int cows = 0;
        int bulls = 0;
        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == g[i]){
                bulls++;
            }
            else
                // so here we are saying if s[i] is negative that means it appeared somewhere in the wrong direction.
                // numbers[secret.charAt(i)-'0'] is negative only if this character appeared in the guess more times 
                // then in the secret which means that this character in the 
                // secret can be matched with one of the previous characters in the guess.
                if(mp[s[i]] < 0){
                    cows++;
                }
                if(mp[g[i]] > 0){
                    cows++;
                }
                mp[s[i]] ++;
                mp[g[i]] --;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";

    }
};
