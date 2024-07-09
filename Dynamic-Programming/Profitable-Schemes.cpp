class Solution {
// The recurrence works as expected. The memoization however took alot of memory. still worked but not the best.
public:
    int min_prof;
    const int mod = 1e9 + 7;

    int kev(int i, int n, int profit, const vector<int> &g,const vector<int> &p, vector<vector<vector<int>>>  &dp) {
        if (n < 0)  return 0;

        if (i == g.size() && profit >= min_prof) return 1;

        if (i == g.size()) return 0;

        if (dp[i][n][profit] != -1) return dp[i][n][profit]; 

        return dp[i][n][profit] = (kev(i + 1, n - g[i], profit + p[i], g, p, dp) + kev(i + 1, n, profit, g, p, dp)) % mod;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        min_prof = minProfit;
        vector<vector<vector<int>>> dp(group.size(), vector<vector<int>> (n + 1, vector<int> (9500, -1)));
        // unordered_map<string, int> dp;
        return kev(0, n, 0, group, profit, dp);
    }
};


class Solution {
// Okay i just discovered we can improve the SC by just taking the min_profit index of the 3D vector as 101 only
// All we need is the profit to be equal to the min profit (its useless to just continue increasing the prof after 
// it matched min prof. So in the next pick kev call we can just set profit as min profit.
public:
    int min_prof;
    const int mod = 1e9 + 7;

    int kev(int i, int n, int profit, const vector<int> &g,const vector<int> &p, vector<vector<vector<int>>>  &dp) {
        if (n < 0)  return 0;

        if (i == g.size() && profit >= min_prof) return 1;

        if (i == g.size()) return 0;

        if (dp[i][n][profit] != -1) return dp[i][n][profit];
        
        int pick = 0;

        if (profit + p[i] >= min_prof)
            pick = kev(i + 1, n - g[i], min_prof, g, p, dp);
        else 
            pick = kev(i + 1, n - g[i], profit + p[i], g, p, dp);

        return dp[i][n][profit] = (pick + kev(i + 1, n, profit, g, p, dp)) % mod;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        min_prof = minProfit;
        vector<vector<vector<int>>> dp(group.size(), vector<vector<int>> (n + 1, vector<int> (101, -1)));
        
        return kev(0, n, 0, group, profit, dp);
    }
};


class Solution {
// So about the commented part, Well in my recursion the condition is no matter what value of n is,
// if it gets us a minProfit then its 1. 
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(group.size() + 1, vector<vector<int>> (n + 1, vector<int> (minProfit + 1 , 0)));
        const int mod = 1e9 + 7;
        int sz = group.size(), ans = 0;
        dp[0][0][0] = 1;

        for (int i = 0; i <= n; i ++) {
            dp[0][i][0] = 1;
        }

        for (int i = 1; i <= sz; i++) {
            // i need to do some research on why it is i - 1.
            int g = group[i - 1];
            int p = profit[i - 1];
            
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= minProfit; k++) {
                    int pick = 0;
                
                    if (j >= g) {
                        pick = dp[i - 1][j - g][max(0,k - p)];
                    }
                    
                    dp[i][j][k] = (pick + dp[i - 1][j][k]) % mod;
                }
            }
        }


        // for (int i = 0; i <= n; i ++) {
        //     ans = (ans + dp[sz][i][minProfit]) % mod;
        // }

        return dp[sz][n][minProfit];
     }
};


class Solution {
// This is apparently the optimized solution, idk why J and K are reversed. I need to do research on that as well.
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(n + 1, vector<int> (minProfit + 1 , 0));
        const int mod = 1e9 + 7;
        int sz = group.size();
        for (int i = 0; i <= n; i ++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= sz; i++) {
            int g = group[i - 1];
            int p = profit[i - 1];
            
            for (int j = n; j >= 0; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    int pick = 0;
                
                    if (j >= g) {
                        pick = dp[j - g][max(0,k - p)];
                    }
                    
                    dp[j][k] = (pick + dp[j][k]) % mod;
                }
            }
        }

        return dp[n][minProfit];
     }
};
