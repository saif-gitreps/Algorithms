class Solution {
// holyy sheet this worked, but it shows TLE, worked till 50 cases.
public:
    void kev(int m,int n,int row,int col,int &ans){
        if(m==row && n==col){
            ans += 1;
            return;
        }
        if(m<row){
            m += 1;
            kev(m,n,row,col,ans);
            m -= 1;
        }
        if(n<col){
            n += 1;
            kev(m,n,row,col,ans);
            n -= 1;
        }
    } 
    int uniquePaths(int m, int n) {
        int ans =0;
        kev(1,1,m,n,ans);
        return ans;
    }
};


class Solution {
// logic wise , this seem correct but idk why i am gettng memory access errors.
public:
    int kev(int m,int n,vector<vector<int>> &dp){
        if(m == 1 && n == 1){
            return 1;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        int up = 0;
        if( m > 1){
            up = kev(m - 1, n, dp);
        }
        int left = 0;
        if( n > 1){
            left = kev(m, n - 1, dp);
        }
        dp[m][n] = left + up;
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        kev(m,n,dp);
        return dp[m][n];
    }
};


class Solution {
// YAY this dp worked. hehe , lets study the optimal solutions.
// i had to declare n+1 and m+1 arrays idk why.
public:
    int kev(int m,int n,vector<vector<int>> &dp){
        if(m == 1 && n == 1){
            dp[m][n] = 1;
            return 1;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        int up = 0;
        if( m > 1){
            m--;
            up = kev(m, n, dp);
            m++;
        }
        int left = 0;
        if( n > 1){
            n--;
            left = kev(m, n, dp);
            n++;
        }
        dp[m][n] = left + up;
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        kev(m,n,dp);
        return dp[m][n];
    }

};
class Solution {
// tabulation method .
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i = 0; i < m ;i ++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1; continue;
                }
                // basically i am storying up + left in dp[i][j].
                dp[i][j] = (i > 0? dp[i-1][j] : 0)
                        +  (j > 0? dp[i][j-1] : 0);
            }
        }

        return dp[m-1][n-1];
    }
};

class Solution {
// space optimized
public:
    int uniquePaths(int m, int n) {
        vector<int> curr(n, 0), prev(n, 0);
        
        curr[0] = 1;
        prev[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) 
                    continue;
                curr[j] = 
                    (i-1 >= 0 ? prev[j] : 0) + 
                    (j-1 >= 0 ? curr[j-1] : 0);
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};

//==========================================================================
//combinatoics solution:
// idea is that we will always take m-1 direction and m-1 direction, means if col is 3 , 
// we will definitely have to move 2 steps from top-left.
// so m-1  + n -1 = (m + n - 2) is the total number of directions i can choose.
// so we have combinatics forula which is , number<Cn> = (number-2 x number-1 x number) / (n x n-1 x n-2) 
// And we apply this formula in terms of our ans that is TotalDirection<C col-1> || TotalDurection<C row-1>
// For example row=2,col=3, if TotalDirection is (2 + 3 -2) = 3.
// applying => 3<col-1>  =  (1 x 2 x 3) / (2 x 1) = 3 , which is correct and
// "Combinations" formula, 
// and it's often denoted as "C(n, k)" or "n choose k." Its formal representation is:

// C(n, k) = n! / (k! * (n - k)!)

// Where:

// "n" is the total number of items to choose from.
// "k" is the number of items to choose.

class Solution {
public:
    int uniquePaths(int m, int n) {
        int number = m + n - 2;
        int Cr = min(m-1,n-1);

        double ans = 1;
        for(int i = 1; i <= Cr; i++){
            ans = ans * (number - Cr + i) / i;
        }
        return (int)ans;
    }
};

