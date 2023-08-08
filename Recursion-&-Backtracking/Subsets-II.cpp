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

class Solution {
//works 100%
public:
    void rev(int i,vector<int> a,vector<int> &ds,vector<vector<int>> &ans){
        if(i>=a.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(a[i]);
        rev(i+1,a,ds,ans);
        ds.pop_back();
        while(i+1<a.size() && a[i]==a[i+1]){
            // ex 144445 , takes only one , skips all.
            i++;
        }
        rev(i+1,a,ds,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        rev(0,nums,ds,ans);
        return ans;
    }
};
