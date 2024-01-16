class Solution {
/* intuition :
     base case : 
     when we exhaust S , that means we can add additional j + 1(index + 1 is the no. of chars)
     to match S and T.
     When we exhaust T, then we need to delete i + 1 characters to match S and T.
   
   When we match a char we just move ahead with both the strings.

   Replacing action is hypotetically accepting that S == T and then moving i - 1 and j - 1.
   Deleting is moving i - 1.
   Inserting is moving j - 1. That means we hypotetically added a Matching character and then moved j - 1,
   Although i stays at the same index. We assume we inserted one and matched hence J was moved ahead.
   
   If we perform any of this action then we add +1 to it.(genious solution).
*/
public:
    int kev(int i , int j, string s, string t, vector<vector<int>> &dp){
        if(i < 0){
            return j + 1;
        }
        if(j < 0){
            return i + 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return kev(i - 1, j - 1, s, t, dp);
        }
        int ans = min(kev(i - 1, j - 1, s, t, dp), 
                    min(
                        kev(i , j - 1, s, t, dp),
                        kev(i - 1, j , s, t, dp)
                    )
                ) + 1;
        return dp[i][j] = ans;
    }

    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return kev(n - 1, m - 1, s, t, dp);
    }
};
