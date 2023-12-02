class Solution {
public:
    int kev(int n, int sum, vector<int> a, vector<vector<int>> &dp){
        if(n == 0){
            if(sum == 0 && a[n] == 0){
                return 2;
            }
            if(sum == 0 || sum == a[n] ){
                return 1;
            }
            return 0;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        // i am lazy to write pick and not pick vairables lmao.
        int pick = 0;
        int not_pick = 0;
        if(sum >= a[n]){
            pick = kev(n-1, sum-a[n], a, dp);
        }
        not_pick = kev(n-1, sum, a, dp);
        return dp[n][sum] = pick + not_pick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto s: nums){
            sum += s;
        }
        //eq1 : s1 + s2 = Ts -- (1)
        //eq2 : s1 - s2 = target -- (2)
        //solve for (3) =>
        //s1(required subset sum) = (Ts - Target)/2
        if(sum - target < 0){
            return 0;
        }
        //difference between the total sum and target sum must be even.
        if((sum - target) % 2 != 0){
            return 0;
        }
        int reqSubSum = (sum - target)/2;
        vector<vector<int>> dp(n, vector<int> (reqSubSum + 1, -1));
        return kev(n-1, reqSubSum, nums, dp);
    }
};


class Solution {
// tabulation.
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto s: nums){
            sum += s;
        }
        //eq1 : s1 + s2 = Ts -- (1)
        //eq2 : s1 - s2 = target -- (2)
        //solve for (3) =>
        //s1(required subset sum) = (Ts - Target)/2
        if(sum - target < 0){
            return 0;
        }
        //difference between the total sum and target sum must be even.
        if((sum - target) % 2 != 0){
            return 0;
        }
        int reqSubSum = (sum - target)/2;
        vector<vector<int>> dp(n, vector<int> (reqSubSum + 1, 0));
        //return kev(n-1, reqSubSum, nums, dp);
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j <= reqSubSum; j++){
                if(i == 0){
                    if(j == 0 && nums[i] == 0){
                        dp[i][j] = 2;
                    }
                    else if(j == 0 || j == nums[i]){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                else{
                    int pick = 0;
                    int not_pick = 0;
                    if(j >= nums[i]){
                        pick = dp[i-1][j - nums[i]];
                    }
                    not_pick = dp[i-1][j];
                    dp[i][j] = pick + not_pick;
                }
            }
        }
        return dp[n-1][reqSubSum];
    }
};
