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

bool compare(vector<int> f, vector<int> s){
    // we are sorting in terms of the ones that will give us more profit
    // 200 - 30 = 170 , means we will save 170 if we take A.
    // will be sorted DESC of relative cost of B - A.
    return f[1] - f[0] > s[1] - s[0];
}
class Solution {
// one of the sol.
public:
    int twoCitySchedCost(vector<vector<int>>& a) {
        int mn = 0;
        sort(a.begin(),a.end(),compare);

        // first loop , it will be economical to take A.
        for(int i = 0; i < a.size()/2; i++){
            mn += a[i][0];
        }

        for(int i = a.size()/2; i < a.size(); i++){
            mn += a[i][1];
        }
        return mn;
    }   
};

class Solution {
// YESSS, the dp solution that actually worked, i thought dp was not possible. tho its O(N^2), here we didnt hash N.
// And i had trouble with the base case as well.
public:
    int kev(int n, int c1,int c2,  vector<vector<int>> a,vector<vector<int>> &dp){
        if(n < 0){
            return 0;
        }
        if(dp[c1][c2] != -1){
            return dp[c1][c2];
        }
        int first = INT_MAX,second = INT_MAX;
        if(c1 > 0){
            first = a[n][0] + kev(n-1, c1-1, c2, a, dp);
        }
        if(c2 > 0){
            second = a[n][1] + kev(n-1, c1, c2-1, a, dp);
        }
        return dp[c1][c2] = min(first, second);
    }
    int twoCitySchedCost(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> dp (51, vector<int> (51,-1));
        return kev(n -1 , n/2 , n/2, a, dp);
    }
};
