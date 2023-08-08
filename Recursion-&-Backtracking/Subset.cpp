class Solution {
public:
    void rev(int i,vector<int> &a,vector<int> &ds,vector<vector<int>> &ans){
        if(i>=a.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(a[i]);
        rev(i+1,a,ds,ans);
        ds.pop_back();
        rev(i+1,a,ds,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        rev(0,nums,ds,ans);
        return ans;
    }
};
