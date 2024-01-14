class Solution {
// had similar idea, but didnt know this type of map.
// dp[n][diff] is max len till index i with common difference of Diff.
// if u had a 2 Dp where u are sure of of the first changing param but not second use this Ds.
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }
        int mx = 0;
        unordered_map<int, int> dp[n+1];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = nums[i] - nums[j];
                int count = 1;

                if(dp[j].count(diff)){
                    count = dp[j][diff];
                }
                dp[i][diff] = 1 + count;
                mx = max(mx, dp[i][diff]);
            }
        }
        return mx;
    }      
};
