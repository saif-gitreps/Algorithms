class Solution {
public:
    double kev(int a, int b, map<pair<int, int>, double> &dp){
        if(a <= 0 and b <= 0){
            return 0.5;
        }
        if(a <= 0){
            return 1.0;
        }
        if(b <= 0){
            return 0.0;
        }
        if(dp.count( {a, b} )){
            return dp[{a, b}];
        }
        double ans = 0.25 * (
            kev(a - 100, b, dp) +
            kev(a - 75, b - 25, dp) +
            kev(a - 50, b - 50, dp) +
            kev(a - 25, b - 75, dp)
        );

        return dp[{a, b}] = ans;
    }
    double soupServings(int N) {
        if(N > 4800){
            return 1;
        }
        map<pair<int, int>, double> dp; 
        return kev(N, N, dp);
    }  
};

class Solution {
// idk why i didnt understand this, this was a traditional dp problem , 
// for 4800 case, when A starts to get bigger, the probaility of A becoming 1 is close.
// because A is designed to be finished first since B never has a case where 100 is serverd from it.
public:
    double kev(int a, int b, vector<vector<double>> &dp){
        if(a <= 0 and b <= 0){
            return 0.5;
        }
        if(a <= 0){
            return 1.0;
        }
        if(b <= 0){
            return 0.0;
        }
        if(dp[a][b] != -1.0){
            return dp[a][b];
        }
        double ans = 0.25 * (
            kev(a - 100, b, dp) +
            kev(a - 75, b - 25, dp) +
            kev(a - 50, b - 50, dp) +
            kev(a - 25, b - 75, dp)
        );

        return dp[a][b] = ans;
    }
    double soupServings(int N) {
        if(N > 4800) return 1;

        vector<vector<double>> dp(N + 1, vector<double> (N + 1, -1.0));
        return kev(N, N, dp);
    }
    
};
