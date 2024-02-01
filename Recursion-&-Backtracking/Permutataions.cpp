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

class Solution {
// best solution in terms of space complexity and time complexity.
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


class Solution {
/*
  
first, we try to find the breaking point
, if no breaking point then send rev of that arr and return;

if we find a breaking point, then try to find the smallest from n - 1 till the breaking point,
swap the smallest, and break.

then one thing we know is since we found the breaking point, 
anything after that is sorted in the reverse order, so we reverse everything after the breaking point.
thats it.
*/
public:
    void nextPermutation(vector<int>& nums) {
        int bp = -1;
        for(int i = nums.size() - 1; i >= 1; i--){
            if(nums[i - 1] < nums[i]){
                bp = i - 1;
                break;
            }
        }
        if(bp == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = nums.size() - 1; i > bp; i--){
            if(nums[i] > nums[bp]){
                swap(nums[i], nums[bp]);
                break;
            }
        }
        reverse(nums.begin() + bp + 1, nums.end());
        return;
    }
};
