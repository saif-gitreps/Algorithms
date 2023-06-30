class Solution {
//naive solution.
public:
    void kev(vector<int> a,vector<int> &ds,unordered_map<int,bool> mapper,vector<vector<int>> &ans){
        if(ds.size()==a.size()){
            ans.push_back(ds);
        }
        for(int i=0;i<a.size();i++){
            if(mapper[a[i]]==false){
                mapper[a[i]] = true;
                ds.push_back(a[i]);
                kev(a,ds,mapper,ans);
                mapper[a[i]] = false;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        unordered_map<int,bool> mapper;
        kev(nums,ds,mapper,ans);
        return ans;
    }
};
