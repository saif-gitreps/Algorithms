class Solution {
//attemp1 accepted but too naive I think.
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string desired_pattern = "";
        unordered_map<char,int> mp;
        vector<string> ans;
        for(int i = 0; i  < pattern.size(); i ++){
            if(mp.count(pattern[i]) == false){
                mp[pattern[i]] = mp.size()+1;
                desired_pattern += mp[pattern[i]];
            }
            else{
                desired_pattern += mp[pattern[i]];
            }
        }
        for(int i = 0 ; i < words.size() ; i ++){
            unordered_map<char,int> temp;
            string temp_pattern = "";
            for(int j = 0; j  < words[i].size(); j ++){
                if(temp.count(words[i][j]) == false){
                    temp[words[i][j]] = temp.size()+1;
                    temp_pattern += temp[words[i][j]];
                }
                else{
                    temp_pattern += temp[words[i][j]];
                }
            }
            if(temp_pattern == desired_pattern){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};




string kev(string w) {
        // its the same concept as my solution,
        // We didnt need to declare another string var.
        // We use the existign string Var, reducing SC.
        unordered_map<char, int> mp;
        for (char c : w){ 
            if (!m.count(c)){ 
                m[c] = m.size();
            }
        }
        for (int i = 0; i < w.length(); ++i){
            w[i] = 'a' + m[w[i]];
        }
        return w;
    }
    vector<string> findAndReplacePattern(vector<string> words, string p) {
        // so this is basically a reduced version of my idea.
        // Didnt get the idea of using a helper function.
        // Helper function over here reduces the space complexity.
            vector<string> ans;
            string p = kev(p);
            for (string w : words) if (kev(w) == p){
                res.push_back(w);
            }
            return res;
        }