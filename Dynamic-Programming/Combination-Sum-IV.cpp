class Solution {
public:
    int kev(vector<int> paths,int sum,vector<int> &a, int &t, unordered_map<string, int> &dp) {
        if (sum > t) return 0;
        if (sum == t) return 1;

        int count = 0;
        string key = "";
        for(auto path : paths)
            key += path;

        if(dp.find(key) != dp.end()) return dp[key];

        for(int i = 0; i < a.size(); i++){
            paths.push_back(i);
            count += (kev(paths, sum + a[i], a, t, dp));
            paths.pop_back();
        }

        return dp[key] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        vector<int> path;
        return kev(path, 0, nums, target, dp);
    }
};
