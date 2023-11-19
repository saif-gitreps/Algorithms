class Solution {
// one of the attempt , passed 147/163
public:
    int kev(int n, int sum, vector<int> a, vector<vector<int>> &dp){
        if(n < 0){
            return 0;
        }
        if(sum == 0){
            return dp[n][sum] = 1;
        }
        if(n == 0){
            if(sum == a[n]){
                return dp[n][sum] = 1;
            }
            return dp[n][sum] = 0;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        int pick = 0;
        int not_pick = 0;
        if(sum >= a[n]){
            pick = kev(n-1 , sum - a[n], a, dp);
        }
        not_pick = kev(n-1, sum, a, dp);
        return dp[n][sum] = pick + not_pick;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i ++){
            sum += nums[i];
        }
        if(sum % k != 0){
            return false;
        }
        vector<vector<int>> dp(n, vector<int> ((sum/k)+1, -1));
        int ans = kev(n-1 , sum/k, nums, dp);
        
        return ans >= k ? true : false;
    }
};
