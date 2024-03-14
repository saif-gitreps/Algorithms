class Solution {
// we take a word, we will find substr o...i + 1, and i + 1 till end.
// ex. catDogCats, cat : dogCats , prf suff ration, we tell recusion to find if suff and pref is in word.
// instead of traditional dp where we take the smaller one to build the bigger.
// we isntead take the bigger one and break it down.

public:
    unordered_map<string , bool> dp;
    bool dfs(string word, unordered_set<string> &mp){
        if(dp.count(word)){
            return dp[word];
        }

        for(int i = 0; i < word.size(); i++){
            string pref = word.substr(0, i + 1);
            string suff = word.substr(i + 1);

            if(
                mp.find(pref) != mp.end() && dfs(suff, mp) or
                mp.find(pref) != mp.end() && mp.find(suff) != mp.end()
                ){
                    return dp[word] = true;
            }
        }
        return dp[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> mp;
        int mx_len = 0;
        
        for(auto word: words){
            mp.insert(word);
            int len = words.size();
            mx_len = max(mx_len, len);
        }
        
        vector<string> ans;
        
        for(int i = 0; i < words.size(); i++){
            if(dfs(words[i], mp)){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
