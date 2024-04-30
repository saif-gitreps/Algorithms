class Solution {
// intuition was, it is the same as Longest common subsequence but instead we are dealing with ASCIS.
// Here this sol showed MLE.
public:
    vector<vector<int>> dp;
    int kev(int i, int j, string s1, string s2){
        if(i <0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return s1[i] + kev(i - 1, j - 1, s1, s2);
        }

        return dp[i][j] = max(
            kev(i - 1, j, s1, s2), 
            kev(i, j - 1, s1 , s2)
        );
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(); int m = s2.size();

        dp.resize(n, vector<int> (m, -1));
        
        int res = kev(n - 1, m - 1, s1, s2);

        int total1 = 0, total2 = 0;
        for(auto s : s1){
            total1 += s;
        }
        for(auto s : s2){
            total2 += s;
        }

        return (total1 - res) + (total2 - res);
    }
};
