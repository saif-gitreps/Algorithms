class Solution {
public:
    void kev(int ind,vector<int> &a,vector<vector<int>> &ans){
        if(ind>=a.size()){
            ans.push_back(a);
            return;
        }
        for(int i=ind;i<a.size();i++){
            swap(a[ind],a[i]);
            kev(ind+1,a,ans);
            swap(a[ind],a[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        kev(0,nums,ans);
        return ans;
    }
};