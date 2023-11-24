class Solution {
// naive dp solution , TLE at 19.
public:
    int kev(int n, int sum, vector<int> a, vector<vector<int>> &dp){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            if((sum + a[n]) % 3 == 0){
                return sum + a[n];
            }
            else if(sum % 3 == 0){
                return sum;
            }
            return 0;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        int pick = 0;
        int not_pick = 0;
        pick = kev(n-1 , sum + a[n], a, dp);
        not_pick = kev(n-1, sum, a, dp);
        return dp[n][sum] = max(pick, not_pick);
    }
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return kev(n-1, 0, nums, dp);
    }
};
