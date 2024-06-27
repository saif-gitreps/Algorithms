class Solution {
public:
    // problem with this approach is that it is complete brutefoce , even with the memoization.
    int kev(vector<int> paths,int sum,vector<int> &a, int &t, unordered_map<string, int> &dp) {
        if (sum > t) return 0;
        if (sum == t) return 1;

        int count = 0;
        string key = "";
        for(auto path : paths)
            key += (path + '0');
        
        key += to_string(sum);

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

class Solution {
// The thing that stopped me from just memoizing sum is that , there are use of different indexes
// so i thought it would give incomplete result but that wasnt the actualy case, it does make sense
// if you think about it to just memoize the sum.
public:
    int kev(int sum,vector<int> &a, int &t, vector<int> &dp) {
        if (sum > t) return 0;
        if (sum == t) return 1;

        int count = 0;

        if(dp[sum] != -1) return dp[sum];

        for(int i = 0; i < a.size(); i++){
            count += (kev(sum + a[i], a, t, dp));
        }

        return dp[sum] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        
        return kev(0, nums, target, dp);
    }
};
