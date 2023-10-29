class Solution {
// this was a dp attempt , although this is apparently prefix sum and greedy solution.
public:
    int kev(int n, int sum, vector<int> &a, int k, vector<int> &dp){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            if(sum + a[n] == k){
                return 1;
            }
            return 0;
        }
        if(sum == k){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int pick = 0;
        int not_pick = 0; 
        pick = kev(n-1, sum+a[n], a, k, dp);
        not_pick = kev(n-1, sum, a, k, dp);
        return dp[n] = pick + not_pick;
    }
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return kev(n-1, 0, nums, k, dp);
    }
};
