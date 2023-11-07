    bool compare(vector<int> i1, vector<int> i2)
    {
        return (i1[0] + i1[1] < i2[0] + i2[1]);
    }
class Solution {
// dp attempt , didnt work.
public:
    int kev(int n, int c1,int c2,  vector<vector<int>> a,vector<vector<vector<int>>> &dp){
        if(n == 0){
            if(c1 == 1){
                return a[n][0];
            }
            return a[n][1];
        }
        if(dp[n][c1][c2] != -1){
            return dp[n][c1][2];
        }
        int first = 10000,second = 10000;
        if(c1 > 1){
            first = a[n][0] + kev(n-1, c1-1, c2, a, dp);
        }
        if(c2 > 1){
            second = a[n][1] + kev(n-1, c1, c2-1, a, dp);
        }
        return dp[n][c1][c2] = min(first, second);
    }
    int twoCitySchedCost(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), compare);
        int n = a.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (51, vector<int> (51,-1)));
        return kev(n -1 , n/2, n/2, a, dp);
    }
};
