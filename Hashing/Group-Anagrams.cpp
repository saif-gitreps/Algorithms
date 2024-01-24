class Solution {
//Not many thoughts were given, just a pure brute force attempt, it worked, haha.
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int> , vector<string>> mp;
        for(auto str : strs){
            map<char, int> temp_mp;
            for(auto s : str){
                temp_mp[s]++;
            }
            mp[temp_mp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto arr : mp){
            ans.push_back(arr.second);
        }
        return ans;
    }
};
