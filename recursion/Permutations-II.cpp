class Solution {
//naive solution
public:
    void kev(int i,vector<int> &a,set<vector<int>> &ans){
        if(i>=a.size()){
            ans.insert(a);
        }
        for(int j = i;j<a.size();j++){
            swap(a[j],a[i]);
            kev(i+1,a,ans);
            swap(a[j],a[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        kev(0,nums,s);
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};
