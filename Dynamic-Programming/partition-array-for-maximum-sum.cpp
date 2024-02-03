class Solution {
public:
    int kev(int i, int k, vector<int> &a, vector<int> &dp){
        if(i >= a.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int mx = INT_MIN;
        int ans = INT_MIN;
        int len = 0;
        int n = a.size();
        for(int j = i; j < min(n, i + k); j++){
            len++;
            mx = max(mx, a[j]);
            ans = max(ans, mx * len + kev(j + 1, k, a, dp));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1, -1);
        return kev(0, k, arr, dp);
    }
};
