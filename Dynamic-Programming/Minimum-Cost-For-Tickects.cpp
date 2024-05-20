class Solution {
// So this is a tough problem it seems. But thank god i at least figured out the recursion
// I don't know why this algorithm passes 70/70 cases yet somehow it shows MLE.
public:
    vector<vector<int>> dp;
    int kev(int i, int pass, vector<int> a, vector<int> c){
        if(i == a.size()){
            return 0;
        }
        if(dp[i][pass] != -1){
            return dp[i][pass];
        }
        if(pass >= a[i]) {
            return dp[i][pass] = kev(i + 1, pass, a, c);
        }
        return dp[i][pass] = min(
            min(
                c[0] + kev(i + 1, pass, a ,c),
                c[1] + kev(i + 1, a[i] + 6, a, c)
            ),
            c[2] + kev(i + 1, a[i] + 29, a, c)
        );
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(), (vector<int> (400, -1)));

        return kev(0, 0, days, costs);
    }
};

class Solution {
// Used a map instead of 2Dp vector and it worked.
public:
    vector<vector<int>> dp;
    int kev(int i, int pass, vector<int> &a, vector<int> &c, map<pair<int, int>, int> &dp){
        if(i == a.size()){
            return 0;
        }
        if(dp.find({i, pass}) != dp.end()){
            return dp[{i, pass}];
        }
        if(pass >= a[i]) {
            return dp[{i, pass}] = kev(i + 1, pass, a, c, dp);
        }
        return dp[{i, pass}] = min(
            min(
                c[0] + kev(i + 1, pass, a ,c, dp),
                c[1] + kev(i + 1, a[i] + 6, a, c, dp)
            ),
            c[2] + kev(i + 1, a[i] + 29, a, c, dp)
        );
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<pair<int, int>, int> mp;

        return kev(0, 0, days, costs, mp);
    }
};


class Solution {
// A better solution using just O(n) space, now this one solved my confusion of the Pass variable. How do we pass all the days that was to be skipped
// because we picked a ticket(7 passes for +6 ticket). I didnt know that could have been solved with just a single loop till that index
// instead of keeping a pass variable and "if(pass >= a[i]) return dp[{i, pass}] = kev(i + 1, pass, a, c, dp); ".        
public:
    int kev(int i,  vector<int> &a, vector<int> &c, vector<int> &dp){
        if(i == a.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int seven_days = INT_MAX, thirty_days = INT_MAX, j = 0;
        
        for(j = i; j < a.size() && a[j] < a[i] + 7; j++);
        seven_days = min(seven_days, c[1] + kev(j, a, c, dp));
        
        for(j = i; j < a.size() && a[j] < a[i] + 30; j++);
        thirty_days = min(thirty_days, c[2] + kev(j , a, c, dp));

        return dp[i] = min({
            c[0] + kev(i + 1, a, c, dp),
            seven_days,
            thirty_days
        });
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, -1);

        return kev(0, days, costs, dp);
    }
};
