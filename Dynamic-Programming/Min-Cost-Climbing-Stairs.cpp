class Solution {
// this aint easy problem yo , its a hard problem , also passed till 149/280 cases
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if( cost.size() <= 2){
            return min( cost[0], cost[1]);
        }
        int sum = 0,i;
        for(i = 2 ; i < cost.size() ; ){
            if(i == cost.size() - 1 ){
                if(cost[i-1] < ( cost[i - 2] + cost[i]) ){
                    sum += cost[i - 1];
                    i += 2;
                }   
                else{
                    sum += cost[i];
                    sum += cost[i-2];
                    i += 1;
                }
                break;
            }
            if(cost[i-1] < ( cost[i - 2] + cost[i]) ){
                sum += cost[i - 1];
                i += 2;
            }
            else if(cost[i-1] >= ( cost[i - 2] + cost[i])){
                sum += cost[i - 2];
                i += 1;
            }
        }
        return sum;
    }
};



class Solution {
// dp attempts , went till 259/284 cases and showed TLE.
public:
    int kev(int n,vector<int> a,vector<int> &dp){
        if(n == 0){
            dp[n] = a[n];
            return dp[n];
        }
        if( n < 0){
            return 0;
        }
        int fs = kev(n-1,a,dp) + a[n];
        int ss = kev(n-2,a,dp) + a[n];
        dp[n] = min(fs,ss);
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        vector<int> dp2(cost.size(),-1);

        kev(cost.size()-2,cost,dp2);
        kev(cost.size()-1,cost,dp);
        return min(dp2[cost.size()-2],dp[cost.size()-1]);
    }
};


class Solution {
// minor mistake, did use the dp array to avoid calculated sub problem.
public:
    int kev(int n,vector<int> a,vector<int> &dp){
        if(n == 0){
            dp[n] = a[n];
            return dp[n];
        }
        if( n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int fs = kev(n-1,a,dp) + a[n];
        int ss = kev(n-2,a,dp) + a[n];
        dp[n] = min(fs,ss);
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        vector<int> dp2(cost.size(),-1);

        kev(cost.size()-2,cost,dp2);
        kev(cost.size()-1,cost,dp);
        return min(dp2[cost.size()-2],dp[cost.size()-1]);
    }
};


int minCostClimbingStairs(vector<int>& cost) {
    // minimum solution ever.
       int n=cost.size();
        for(int i=2;i<n;i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
}

