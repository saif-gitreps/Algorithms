class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;
        for(auto k: words){
            for(auto p: k){
                mp[p]++;
            }
        }
        for(auto s:mp){
            if(s.second%words.size()!=0) return false;
        }
        return true;
    }
};
