class Solution {
//first attempt , accepted .
public:
    void kev(int i,int k,int n,vector<int> &ds,set<vector<int>> &ans){
        if(ds.size()==k){
            ans.insert(ds);
            return;
        }
        for(int j = i; j <= n; j++ ){
            ds.push_back(j);
            kev(j+1,k,n,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> final_arr;
        set<vector<int>> ans;
        vector<int> ds;
        kev(1,k,n,ds,ans);
        for(auto s: ans){
            final_arr.push_back(s);
        }
        return final_arr;
    }
};
