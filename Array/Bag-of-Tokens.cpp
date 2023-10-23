class Solution {
// naive attempt at a dp solution , cant figure it out to be honest, two pointer or other greedy method should be implemented..
public:
    int kev(int n, int power,vector<int> &a, vector<int> &dp){
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int take_token = 0;
        int ignore = 0;
        int consume = 0;
        if(power >= a[n]){
            consume = kev(n-1, power - a[n], a, dp) + 1;
        }
        if(power < a[n]){
            take_token = kev(n-1, power + a[n], a, dp) - 1;
        }
        ignore = kev(n-1, power , a, dp);
        return dp[n] = max(ignore ,max(take_token, consume));
    }
    int bagOfTokensScore(vector<int>& a, int power) {
        int n = a.size();
        vector<int> dp(n, -1);
        return kev(n-1, power, a, dp);
    }
};
