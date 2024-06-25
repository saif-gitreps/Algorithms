class Solution {
// I feel like the solution would have been much easier to solve if i sat down with a calm thought.
// more like a DFS + memo
public:
    bool are_words_pre(string a, string b){
        int count = 0;
        
        for(int i = 0, j = 0; i < a.size() && j < b.size(); j++){
            if(a[i] != b[j])
                count ++;
            else
                i++;
        }

        return count <= 1;
    }
    int kev(string word, unordered_map<string, int> &dp, map<int, vector<string>> &mp){
        if(mp.find(word.size() + 1) == mp.end())
            return 1;
        
        if(dp.find(word) != dp.end())
            return dp[word];

        vector<string> &words = mp[word.size() + 1];
        int ans = 0;

        for(auto w : words){
            if(are_words_pre(word, w)){
                ans = max(ans,kev(w, dp, mp));
            }
        }

        dp[word] = ans + 1;
        return dp[word];
    }
    int longestStrChain(vector<string>& words) {
        map<int, vector<string>> mp;
        unordered_map<string, int> dp;
        
        for(auto word : words){
            mp[word.size()].push_back(word);
        }

        int ans = 1;
        for(auto word : words){
            ans = max(ans, kev(word, dp, mp));
        }

        return ans;
    }
};

// solved again after 5 days 6 hours , exactly the same

class Solution {
public:
    bool is_valid(string a, string b){
        int count = 0;

        for (int i = 0, j = 0; i < a.size() && j < b.size(); j++){
            if (a[i] != b[j]) count++;
            else i++;
        }

        return count <= 1;
    }

    int dfs(string &word, vector<string>& words, unordered_map<int, vector<string>> &mp, unordered_map<string, int> &dp){
        if (mp.find(word.size() + 1) == mp.end()) return 1;
        if (dp.find(word) != dp.end()) return dp[word];

        int count = 0;
        for (auto w : mp[word.size() + 1])
            if (is_valid(word, w))
                count = max(count , dfs(w, words, mp, dp));

        return dp[word] = count + 1;
    }

    int longestStrChain(vector<string>& words) {
        unordered_map<int, vector<string>> mp;
        unordered_map<string, int> dp;
        
        for (auto word : words) 
            mp[word.size()].push_back(word);

        int count = 1;
        
        for (auto word : words)
            count = max(count, dfs(word, words, mp, dp));

        return count;
    }
};
