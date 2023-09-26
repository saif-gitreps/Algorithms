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


class Solution {
// getting stuck on edge cases all the time, this tine 51/75.
public:
    int kev(int n , vector<int> a, vector<int> &dp){
        if(n == 0){
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
        if(n == a.size() - 1) {
            int min_to_delete = min(a[a.size()-1],a[0]);
            pick = abs(pick - min_to_delete);
        }
        dp[n] = max(pick, not_pick);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        kev(n - 1, nums, dp);
        return dp[n-1];
    }
};


class Solution {
// So the idea missing was that, we either ignore the first element, or we ignore the last element, then tag the max result you get from 
// ignoring either of those indices. I copied and pasted house robber - I's space-optimized solution and made two function calls, a call without 
// 0 index and another without the last index and returned the max from each result. 
public:
    int kev(int n , vector<int> a){
        int prev = 0;
        int curr = a[0];
        for(int i = 1 ; i <= n; i++){
            int pick = a[i] + prev;
            int not_pick = curr;
            prev = curr;
            curr = max(pick , not_pick);
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int temp1 = nums[nums.size()-1];
        int temp2 = nums[0];

        nums[ nums.size()-1 ] = 0;
        int ans1 = kev(nums.size() -1 , nums);
        nums[ nums.size()-1 ] = temp1;

        nums[0] = 0;
        int ans2 = kev(nums.size() -1 , nums);
        return max(ans1,ans2);
    }
};
