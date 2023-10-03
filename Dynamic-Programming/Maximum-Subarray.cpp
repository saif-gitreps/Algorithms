class Solution {
// I knew this algorithm from before , so This algorithm is called Kadane's algorithm.
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int mx = -10001;
        int sum = -10001;
        for(int i = 0 ; i < nums.size(); i ++){
            if( sum + nums[i] >= nums[i]){
                sum += nums[i];
            }
            else{
                sum = nums[i];
            }
            mx = max(sum, mx);
        }
        return mx;
    }
};


class Solution {
// idk this dp approach isnt really the right answe but i tried.
public:
    int kev(int n, vector<int> a, vector<int> &dp){
        if(n == 0){
            return dp[n] = a[0];
        }
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int pick = kev(n-1, a, dp) + a[n];
        int not_pick = kev(n-2, a, dp);
        return dp[n] = max(pick, not_pick); 
    }
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        kev(nums.size()-1 , nums, dp);
        return dp[nums.size()-1];

    }
};
