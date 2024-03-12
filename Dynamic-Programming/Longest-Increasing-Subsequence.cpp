class Solution {
// i thought i submitted this, but i ddint. it is self explanatory.
public:
    int kev(int prev, int i,vector<int> &a, vector<int> &dp){
        if(i >= a.size()){
            return 0;
        }
        
        if(dp[prev + 1] != -1){
            return dp[prev + 1];
        }

        int pick = 0;
        
        int not_pick = kev(prev , i + 1, a, dp);
        
        if(prev == -1 || a[i] > a[prev]){
            pick = 1 + kev(i, i + 1, a, dp);
        }
        return dp[prev + 1] = max(pick, not_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.resize(size(nums) + 1, -1);
        return kev(-1, 0, nums, dp);
    }
};


class Solution {
// try to simulate this -> 5 , 4, 11, 8, 1, 16. Each index is basically an ans of 1.
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.resize(size(nums), 1);
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i], dp[prev] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        
        return ans;

    }
};
