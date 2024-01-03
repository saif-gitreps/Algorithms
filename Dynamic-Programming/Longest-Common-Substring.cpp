class Solution{
public:
    int kev(int i, int j, string s1, string s2, int dp[][1001]){
        if(i < 0 || j < 0){
            return 0;
        }
        if(dp[i][j] != 0){
            return dp[i][j];
        }
        int mx = 0;
        if(s1[i] == s2[j]){
            while(i >=0 && j >= 0 && s1[i] == s2[j]){
                mx++;
                i--;
                j--;
            }
        }
        mx = max(mx, kev(i - 1,j , s1, s2, dp));
        mx = max(mx, kev(i , j - 1, s1, s2, dp));
        dp[i][j] = mx;
        return dp[i][j];
    }
    
    int lcs(string &str1, string &str2){
        int n = str1.size();
        int m = str2.size();
        int dp[1001][1001];
        return kev(n - 1, m - 1, str1, str2, dp);
    }
}

class Solution{
// okay atleast i figured the table out.
// we are not matching and then skipping , we are either matching or we skip. easier to visualize in a table form.
public:
      int lcs(string &text1, string &text2){
          int n = max(text1.size(), text2.size());
          vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, 0));
          int mx = 0;

          for(int i = 0 ; i <= text1.size() ; i ++){
              for(int j = 0 ; j <= text2.size() ; j ++){
                  if(i == 0 || j == 0){
                      dp[i][j] = 0;
                  }
                  else if(text1[i - 1] == text2[j - 1]){
                      dp[i][j] = 1 + dp[i - 1][j - 1];
                      mx = max(dp[i][j], mx);
                  } 
              }
          }
          return mx;
      }
};
