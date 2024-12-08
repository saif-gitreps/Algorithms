class Solution {
// rec + memp TLE.
public:
    int kev(int i, vector<int> a, vector<int> &dp) {
        if (i == a.size() - 1) {
            return 0;
        }
        
        if (i >= a.size()) {
            return 100000;
        }

        if (dp[i] != -1) return dp[i];

        int ans = 100000;
        
        for (int j = 1; j <= a[i]; j++) {
            ans =  min(ans, 1 + kev(i + j, a, dp));
        }

        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return kev(0, nums, dp);
    }
};

class Solution {
// tablation accepted
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 1000000);

        dp[nums.size()-1] = 0;

        for (int i = nums.size()-2; i >= 0; i--) {
            for (int j = 1; j <= nums[i]; j++) {
                if (j + i <= nums.size()-1)
                    dp[i] =  min(dp[i], 1 + dp[j + i]);
            }
        }

        return dp[0];
    }
};
