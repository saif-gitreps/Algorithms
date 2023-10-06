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
