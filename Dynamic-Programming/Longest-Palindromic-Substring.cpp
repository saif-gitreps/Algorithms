class Solution {
/*
  So the problem is with using the same longest common subtring algorithm , the edge case "aacabdkacaa" ,
  Here we are getting aaca as the lcs where it is not a palindrome but since we are using LCS alg , ans is aaca,
  The longest common subsequence algorithm worked for the LPSubsequence.
*/
public:
    string longestPalindrome(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        int mx = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                if(s2[i - 1] == s[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    mx = max(mx, dp[i][j]);
                }
            }
        }
        string ans = "";
        for(int i = 0 ;i < mx; i ++){
            ans += "$";
        }
        int i = n, j = n;
        while(i > 0 && j > 0){
            if(s2[i - 1] == s[j - 1] && dp[i][j] == mx){
                while(s2[i - 1] == s[j - 1]){
                    ans[mx - 1] = s2[i - 1];
                    mx --;
                    i --;
                    j --;
                }
                break;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]){
                i--;
            }
            else{
                j--;
            }
        } 
        return ans;
    }
};

class Solution {
/*
Erichto's solution, Ok so i understood this , we bascially keep a pointer at an index,
and then we expand from that point, while expanding we check if left and right chars are equal
EVery iteration of mid, we pick N points (entire string) then we expand.
The second part is for even characters.
When x = 1 -> mid, mid + 1 -> AA
                              ^^
when x = 2 -> mid - 1, mid + 2 ->  AAAA
                                   ^  ^

*/
public: 
    string longestPalindrome(string s) {
        int best_len = 0;
        string best_s = "";
        int n = s.length();
        for(int mid = 0; mid < n; mid++) {
            for(int x = 0; mid - x >= 0 && mid + x < n; x++) {
                if(s[mid-x] != s[mid+x]) {
                    break;
                }
                int len = 2 * x + 1;
                if(len > best_len) {
                    best_len = len;
                    best_s = s.substr(mid - x, len);
                }
            }
        }
        for(int mid = 0; mid < n - 1; mid++) {
            // so n - 1 because for our mid point issue, 
            // lets say "abba".
            // our mid point here is the first 'b' and expansion starts from there.
            for(int x = 1; mid - x + 1 >= 0 && mid + x < n; x++) {
                if(s[mid-x+1] != s[mid+x]) {
                    break;
                }
                int len = 2 * x;
                if(len > best_len) {
                    best_len = len;
                    best_s = s.substr(mid - x + 1, len);
                }
            }
        }
        return best_s;
    }
};

class Solution{
 // O(n^3) solution. slightly optimized for the inner loop.
 /*
   Here, we first start by marking an imaginary dp table, 
   we first mark all the 1 length chars as 1, then we mark 0-2, 1-3, 2-4
   then 0-3, 1-4, 2-5 so on , then we check if the inner of them was palindrome.

   But this solution was different from the explanation:
   https://www.youtube.com/watch?v=UflHuQj6MVA
 */

public:
  int longestPalSubstr(string str){
    
      int n = str.size();
      int maxLength = 1, start = 0;
   
      for (int i = 0; i < str.length(); i++) {
          for (int j = i; j < str.length(); j++) {
              int flag = 1;
              for (int k = 0; k < (j - i + 1) / 2; k++)
                  if (str[i + k] != str[j - k])
                      flag = 0;
   
              if (flag && (j - i + 1) > maxLength) {
                  start = i;
                  maxLength = j - i + 1;
              }
          }
      }
   
      cout << "Longest palindrome substring is: ";
      printSubStr(str, start, start + maxLength - 1);
      return maxLength;
  }
};

// Two more algorithms to review.
