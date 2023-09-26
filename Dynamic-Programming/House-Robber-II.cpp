class Solution {
// attempt 1: worked till 45/75 test cases.
public:
    int kev(int n , vector<int> a, vector<int> &dp){
        if(n == 0){
            if(a.size()%2 != 0 && a.size()>1){
                return 0;
            }
            dp[n] = a[n];
            return dp[n];
        }
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int pick = a[n] + kev(n - 2, a, dp);
        int not_pick = kev(n - 1, a, dp);
        return dp[n] = max(pick, not_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        kev(n - 1, nums, dp);
        return dp[n-1];
    }
};
