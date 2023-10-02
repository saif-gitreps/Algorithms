#include <bits/stdc++.h>
// attempt1: getting overflow.
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
#define pb push_back
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;

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
   if(m<row && n<col){
      n++;
      kev(m,n,row,col,ans);
      n--;
   }
   if(n<col && m<row){
      m++;
      kev(m,n,row,col,ans);
      m--;
   }
}  

int main(){
   int m;int n;
   cin>>m>>n;
   int ans =0;
   map<pair<int,int>,bool> mp;
   kev(0,0,m,n,ans);
   cout<<ans;
}

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
