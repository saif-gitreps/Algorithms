class Solution {
// This shows TLE TC- O(N * max(S, T)) where S is s and T is every word in words.
public:
    int sub(string s, string t) {
        int ans = 0, j = 0;
        for(int i = 0; i < t.size() && j < s.size(); i++){
            if(s[j] == t[i]){
                j++;
            }
            if(j == s.size()){
                return true;
            }
        }
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        
        for(int i = 0; i < words.size(); i++){
            if(sub(words[i], s)){
                ans++;
            }
        }

        return ans;
    }   
};


class Solution {
// TC -> O(S + N log N) where S is len of s and N is len of words and log N for each word.
// Best Case TC -> O(S + N) ~ O(n). 
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]].push_back(i);
        }
        
        int ans = 0;
        
        for(auto word : words){
            int relative_order = 0;
            bool flag = false;
            for(auto c : word){
                if(mp.find(c) == mp.end()){
                    flag = false;
                    break;
                }
                
                auto it = lower_bound(
                    mp[c].begin(), 
                    mp[c].end(), 
                    relative_order
                );
                
                if(it == mp[c].end()){
                    flag = false;
                    break;
                }
                flag = true;
                relative_order = *it + 1;
            }
            if(flag){
                ans++;
            }
        }

        return ans;
    }   
};
