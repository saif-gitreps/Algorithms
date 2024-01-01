class Solution {
// i guess my best dp attempt yet lol
public:
    int dp[1001][1001][2];
    int kev(int i,int prev , int pos,vector<int> a, int n){
        if(i == n){
            return 0;
        }

        if(dp[i][prev][pos] != 0){
            return dp[i][prev][pos];
        }

        int pick = 0;
        int not_pick = 0;

        if(prev < a[i] && !pos){
            prev = a[i];
            pos = 1;
            pick = 1 + kev(i + 1 , prev, pos ,a , n);
        }
        if(prev > a[i] && pos){
            prev = a[i];
            pos = 0;
            pick = 1 + kev(i + 1, prev, pos, a, n);
        }

        not_pick = 0 + kev(i + 1, prev, pos, a, n);

        return dp[i][prev][pos] = max(pick , not_pick);
    }

    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1){
            return 1;
        }
        memset(dp, 0, sizeof(nums.size())); 
        int prev = nums[0];
        int pos = nums[0] > nums[1];
        return kev(1 ,prev, pos, nums, nums.size()) + 1;
    }
};
