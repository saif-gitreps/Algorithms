class Solution {
// first attempt , comeplete TLE at first 2 cases.
public:
    int minStickers(vector<string>& a, string target) {
        vector<unordered_map<char,int>> mp;
        unordered_map<char,int> t_mp;
        for(int i = 0 ;i < target.size(); i++){
            t_mp[target[i]]++;
        }
        for(int i = 0 ; i < a.size(); i++){
            unordered_map<char,int> temp;
            for(int j = 0 ; j < a[i].size(); j++){
                temp[a[i][j]]++;
            }
            mp.push_back(temp);
        }
        int total_count = 0;
        for(int i = 0 ; i < mp.size(); i++){
            int mx_count = 0;
            for(auto p : t_mp){
                int count = 0;
                while(mp[i].count(p.first)){
                    int decrement = p.second - 1;
                    p.second = decrement;
                    count++;
                }
                mx_count = max(mx_count,count);
            }
            total_count += mx_count;
        }
        return total_count == 0? -1 : total_count;
    }
};


class Solution {
public:
    int kev(string target, vector<vector<int>> mp, unordered_map<string,int> &dp){
        if(dp.count(target)){
            return dp[target];
        }
        int n = mp.size();
        int ans = INT_MAX;
        vector<int> mini(26,0);
        for(int i = 0 ; i < target.size(); i++){
            mini[target[i] - 'a']++;
        }
        for(int i = 0; i < n; i++){
            if(mp[i][target[0] - 'a'] == 0){
                continue;
            }
            string s;
            for(int j = 0; j < 26; j++){
                if(mini[j] - mp[i][j] > 0){
                    s += string(mini[j] - mp[i][j], 'a' + j);
                }
            }
            int tmp = kev(s, mp, dp);
            if( tmp != -1){
                ans = min(ans, 1 + tmp);
            }
        }
        return dp[target] = ans == INT_MAX ? -1 : ans;
    }
    int minStickers(vector<string>& a, string target) {
        int n = a.size();
        vector<vector<int>> mp(a.size(), vector<int>(26,0));
        unordered_map<string, int> dp;
        for(int i = 0 ; i < a.size(); i++){
            for(int j = 0 ; j < a[i].size(); j++){
                mp[i][a[i][j] - 'a']++;
            }
        }
        dp[""] = 0;
        return kev(target, mp, dp);
    }
};
