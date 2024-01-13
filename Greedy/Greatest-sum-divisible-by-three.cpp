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


class Solution {

https://www.youtube.com/watch?v=fH-d_w3Cs4g
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(3, vector<int> (n, 0));
        dp[nums[0] % 3][0] = nums[0];

        for(int i = 1; i < n; i++){
            int res0 = (nums[i] + dp[0][i -1]) % 3;
            int res1 = (nums[i] + dp[1][i -1]) % 3;
            int res2 = (nums[i] + dp[2][i -1]) % 3;

            dp[res0][i] = max(dp[res0][i], dp[0][i -1] + nums[i]);
            dp[res1][i] = max(dp[res1][i], dp[1][i -1] + nums[i]);
            dp[res2][i] = max(dp[res2][i], dp[2][i -1] + nums[i]);

            dp[0][i] = max(dp[0][i - 1], dp[0][i]);
            dp[1][i] = max(dp[1][i - 1], dp[1][i]);
            dp[2][i] = max(dp[2][i - 1], dp[2][i]);
        }
        return dp[0][n-1];
    }
};
