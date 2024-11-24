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

class Solution {
// did tab successfully.
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        for(int j = 0 ; j <= m; j++){
            dp[0][j] = j;
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = i;
        }
        for(int i = 1; i <= n ; i ++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};



class Solution {
// revisit after a year.
/*
    latest understanding:
    Max is word1.size() + word1.size(). Where we have to remove
    every letter from word1 and add every letter there is on word2. 
    We know we will get an LCS , we are trying to see the minimum number
    of letters that dont match - LCS.
    For the base case, I am having hard time putting into sentence.
    lets say a = "bcde" b = "b", we reached at the end of b index. now to 
    count the letters that are need to finish b is number of remaining chars 
    in a, and we have the index number as well which is i. 
*/
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));

        for (int j = 0; j <= m; j++) {
            dp[0][j] = j; 
        }

        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min (
                        dp[i-1][j-1],
                            min (
                            dp[i-1][j],
                            dp[i][j-1]
                        )
                    );
                }
            }
        }

        return dp[n][m];
    }
};
