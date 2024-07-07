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
