class Solution {
// best attempt with DP. 31/126 cases.
public:
    int kev(int n, int screen, int clipboard, bool canCopy, vector<vector<int>> &dp){
        if(screen == n){
            return 0;
        }
        if(screen > n){
            return 0;
        }
        if(dp[screen][clipboard] != -1){
            return dp[screen][clipboard];
        }
        int copy = INT_MAX, paste = INT_MAX;
        if(canCopy){
            copy = 1 + kev(n, screen, screen, 0, dp);
        }
        if(clipboard > 0){
            paste = 1 + kev(n, screen + clipboard, clipboard, 1, dp);
        }
        return dp[screen][clipboard] = min(copy , paste);
    }
    int minSteps(int n) {
        if(n == 1) {
            return 0;
        }
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return kev(n, 1, 0, 1, dp);    
    }

};

/*   
    wrote the solution in python3, 
    the theory is that we use prime factorization as method that represents copy and paste.
    example for test case 18. We know  2 is divisor, that basically means when we have 9 A's on 
    the screen, we can do a copy + paste (2) to get 18.
    next iteration, it is 9, that means we got 3 A's, we can copy + paste + paste (3).
    next iteration, it is 3, that means we got 1 A, copy + paste + paste (3).

    next time think of factorization as a way to break down problems into smaller manageable parts.
    
 */     
class Solution:
    def minSteps(self, n: int) -> int:
        ans = 0
        for d in range(2, n + 1):
            while n % d == 0:
                ans += d
                n /= d
        
        return ans
        

