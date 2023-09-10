class Solution {
// without dp , TLE in case 25.
public:
    void stairs(int n,int stair,int &count){
    if(n==0){
        count++;
        return;
    }
    if(n-2 >= 0){
        stairs(n-2,stair,count);
    }
    if(n-1 >= 0){
        stairs(n-1,stair,count);
    }
    }
    int climbStairs(int n) {
        int count = 0 ;
        stairs(n,n,count);
        return count;
    }
};


class Solution {
// i have to analyze how this works like the fibonnaci
public:
    int dp[100];
    int stairs(int n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = stairs(n-1) + stairs(n-2);
        return dp[n];
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return stairs(n);
    }
};
