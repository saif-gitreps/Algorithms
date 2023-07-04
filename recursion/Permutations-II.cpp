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
class Solution {
// best in terms of space complexity but works for 14/33 test cases only.
public:
    void kev(int i,vector<int> &a,vector<vector<int>> &ans){
        if(i>=a.size()){
            ans.push_back(a);
        }
        for(int j = i;j<a.size();j++){
            if(j!=i && a[j]==a[i]){
                continue;
            }
            swap(a[j],a[i]);
            kev(i+1,a,ans);
            swap(a[j],a[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // set<vector<int>> s;
        vector<vector<int>> ans;
        kev(0,nums,ans);
        // for(auto x:s){
        //     ans.push_back(x);
        // }
        return ans;
    }
};

