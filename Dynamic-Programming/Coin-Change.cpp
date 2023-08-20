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
