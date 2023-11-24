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


class Solution {
// This tabulation worked, but i got stuck in an edge case.
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, 0));
        //return kev(n-1, 0, nums, dp);
        for(int i = 0 ; i < n; i++){
            for(int val = sum; val >= 1; val--){
                if(i == 0){
                    if(val % 3 == 0){
                        dp[i][val] = val;
                    }
                    else{
                        dp[i][val] = 0;
                    }
                    continue; 
                }
                int pick = 0;
                int not_pick = 0;
                if(val - nums[i] >= 0){
                    pick = dp[i-1][val - nums[i]];
                }
                not_pick = dp[i-1][val];
                dp[i][val] = max(pick, not_pick); 
            }
        }
        return dp[n-1][sum];
    }
};
