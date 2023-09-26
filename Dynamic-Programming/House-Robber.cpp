class Solution {
public:
    int rob(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < nums.size() ; i ++ ){
            if(i%2==0){
                sum1 += nums[i];
            }
            else {
                sum2 += nums[i];
            }
        }
        return sum1>sum2? sum1:sum2;
    }
};


class Solution {
public:
    int kev(int n , vector<int> a , vector<int> &dp){
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
        int pick = a[n] + kev(n - 2 , a, dp);
        int not_pick = kev(n - 1, a , dp);
        return dp[n] = max(pick,not_pick);
     }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1 );
        kev(nums.size()-1, nums, dp);

        return dp[nums.size() - 1 ];
    }
};


class Solution {
// space optimized solution ,
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
        return kev(nums.size()-1, nums);
    }
};
