class Solution {
//yay figured out the decision tree. but apparently its not good lmao.
public:
    vector<vector<int>> ans;
    map<vector<int>, bool> mp;
    void kev(int i, vector<int> a, vector<int> ds){
        if(i == a.size()){
            if(mp.find(ds) == mp.end() && ds.size() >= 2){
                mp[ds] = 1;
                ans.push_back(ds);
            }
            return;
        }        
        if(ds.size() == 0){
            ds.push_back(a[i]);
            kev(i + 1, a, ds);
            ds.pop_back();
            kev(i + 1, a, ds);
        }
        else if(ds[ds.size() - 1] <= a[i]){
            ds.push_back(a[i]);
            kev(i + 1, a, ds);
            ds.pop_back();
            kev(i + 1, a, ds);
        }
        else{
            kev(i + 1, a, ds);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //vector<vector<int>> ans;
        vector<int> ds;
        kev(0, nums, ds);
        return ans;
    }
};

class Solution {
// same solution but using set instead of mp.
public:
    vector<vector<int>> ans;
    set<vector<int>> mp;
    void kev(int i, vector<int> a, vector<int> ds){
        if(i == a.size()){
            if(ds.size() >= 2){
                mp.insert(ds);
            }
            return;
        }        
        if(ds.size() == 0){
            ds.push_back(a[i]);
            kev(i + 1, a, ds);
            ds.pop_back();
            kev(i + 1, a, ds);
        }
        else if(ds[ds.size() - 1] <= a[i]){
            ds.push_back(a[i]);
            kev(i + 1, a, ds);
            ds.pop_back();
            kev(i + 1, a, ds);
        }
        else{
            kev(i + 1, a, ds);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //vector<vector<int>> ans;
        vector<int> ds;
        kev(0, nums, ds);
        
        for(auto array : mp){
            ans.push_back(array);
        } 
        
        return ans;
    }
};


class Solution {
// slightly better solution
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seq;
        dfs(res, seq, nums, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums, int pos) {
        if(seq.size() > 1) res.push_back(seq);
        unordered_set<int> hash;
        for(int i = pos; i < nums.size(); ++i) {
            if((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end()) {
                seq.push_back(nums[i]);
                dfs(res, seq, nums, i + 1);
                seq.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
};

/*
Both solutions have exponential time and space complexity due to the nature of the problem.
However, the second solution might perform better in practice due to its pruning strategy using hashing,
which helps avoid generating duplicate subsequences.

If you have a small input size or if memory consumption is not a concern, 
either solution might work fine. However, for larger input sizes, you might want to consider optimizing 
or modifying the algorithm to reduce its time and space complexity.
*/

// have to analize this someday.
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res(1);
        unordered_map<int,int> ht;
        for(int i=0;i<nums.size();i++) {
            int n = res.size();
            int start = ht[nums[i]];
            ht[nums[i]] = n;
            for(int j=start;j<n;j++)
                if(res[j].empty() || res[j].back()<=nums[i]) {
                    res.push_back(res[j]);
                    res.back().push_back(nums[i]);
                }  
        }
        for(int i=res.size()-1;i>=0;i--) 
            if(res[i].size()<2) {
                swap(res[i],res.back());
                res.pop_back();
            }
        return res;
    }
