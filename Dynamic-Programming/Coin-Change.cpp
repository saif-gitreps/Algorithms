class Solution {
// first attempt , worked till 39 cases and showed TLE ,need to do DP on this.
public:
    int ds_size = INT_MAX;
    void kev(int i,long long sum,long long amt,vector<int> &ds,vector<int> &a){
        if(sum>=amt){
            if(sum==amt){
                int n = ds.size();
                ds_size = min(ds_size,n);
            }
            return;
        }
        for(int j = i ;j < a.size(); j++){
            ds.push_back(a[j]);
            sum += a[j];
            kev(j,sum,amt,ds,a);
            sum -= a[j];
            ds.pop_back();
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ds;
        kev(0,0,amount,ds,coins);
        if(ds_size==INT_MAX){
            return -1;
        }
        return ds_size;
    }
};


class Solution {
// this is better recursion.
public:
    int kev(int n, int t, vector<int> a){
       if(t < 0){
           return 1e9;
       }
       if(n == 0){
           if(t % a[n] == 0){
               return t/a[n];
           }
           else{
               return 1e9;
           }
       }
       // if i wont pick that number then i will move ahead.
       int pick = 1 + kev(n, t - a[n], a);
       // if i will pick the number,
       // i will test the limit and stay at the same index(infinte pick).
       int not_pick = kev(n-1, t, a);
       return min(pick, not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = kev(n-1, amount, coins);
        if(ans == 1e9){
            return -1;
        }
        return ans; 
    }
};
