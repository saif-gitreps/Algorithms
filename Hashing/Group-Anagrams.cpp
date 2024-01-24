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


class Solution {
// i am so stupid, i could have just sorted it out instead of using a whole ass Map to store it.
// anyway atleast the rest of the solution and intuition was good.
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> mp;
        for(auto str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto arr : mp){
            ans.push_back(arr.second);
        }
        return ans;
    }
};
