class Solution {
//worked till 15 cases.
public:
    void rev(int i,vector<int> a,vector<int> &ds,set<vector<int>> &ans){
        ans.insert(ds);
        for(int j=i;j<a.size();j++){
            ds.push_back(a[j]);
            rev(j+1,a,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> arr;
        vector<int> ds;
        rev(0,nums,ds,ans);
        for(auto a:ans){
            arr.push_back(a);
        }
        return arr;
    }
};
