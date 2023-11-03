class Solution {
// Bruteforce works, time to memoize.
public:
    int kev(int n, int s1, int s2, vector<int> a){
        if(n == 0){
            if(s1 + a[n] == s2 || s2 + a[n] == s1){
                return 1;
            }
            return 0;
        }
        int s1_pick = 0;
        int s2_pick = 0;
        s1_pick = kev(n-1, s1+a[n], s2, a);
        s2_pick = kev(n-1, s1, s2+a[n], a);
        return s1_pick || s2_pick;
    }
    bool canPartition(vector<int>& nums) {
        return kev(nums.size()-1, 0, 0, nums);
    }
};

class Solution {
// shows TLE after 41 cases. using 3D array shows memory limit exceeding.
public:
    int kev(int n, int s1, int s2, vector<int> a, vector<map<pair<int,int>,int>> &dp){
        if(n == 0){
            if(s1 + a[n] == s2 || s2 + a[n] == s1){
                return 1;
            }
            return 0;
        }
        pair<int, int> p1 = {s1, s2};
        if (dp[n].find(p1) != dp[n].end()) {
            return dp[n][p1];
        }
        int s1_pick = 0;
        int s2_pick = 0;
        s1_pick = kev(n-1, s1+a[n], s2, a, dp);
        s2_pick = kev(n-1, s1, s2+a[n], a, dp);
        return dp[n][p1] = s1_pick || s2_pick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<map<pair<int,int>,int>> dp(n);  
        return kev(n-1, 0, 0, nums, dp);
    }
};
