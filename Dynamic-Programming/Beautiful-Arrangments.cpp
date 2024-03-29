class Solution {
// naive approach, MLE
public:
    void kev(int ind,vector<int> &a,vector<vector<int>> &ans){
        if(ind >= a.size()){
            ans.push_back(a);
            return;
        }
        for(int i = ind; i < a.size(); i++){
            swap(a[ind], a[i]);
            kev(ind+1, a, ans);
            swap(a[ind], a[i]);
        }
    }

    bool rev(int i, vector<int> &a, vector<int> &dp){
        if(i >= a.size()){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        bool ans = false;
        if (a[i] % (i + 1) == 0 || (i + 1) % a[i] == 0){
            ans = rev(i + 1, a, dp);
        }
        
        return dp[i] = ans;
    }

    int countArrangement(int n) {
        vector<int> nums(n);
        for(int i = 1; i <= n; i++){
            nums[i - 1] = i;
        }

        vector<vector<int>> permutations;
        kev(0, nums, permutations);

        int count = 0;
        for(auto perm : permutations){
            vector<int> dp(perm.size() + 1, -1);
            
            if(rev(0, perm, dp)){
                count++;
            }
        }

        return count;
    }
};

class Solution {
// slightly better but still TLE
public:
    vector<vector<int>> kev(vector<int>& nums) {
        vector<vector<int>> result;
        
        do{
            result.push_back(nums);   
        }while(next_permutation(nums.begin(), nums.end()));

        return result;
    }

    bool rev(vector<int> &a){

        for(int i = 0; i < a.size(); i++){
            if (a[i] % (i + 1) == 0 || (i + 1) % a[i] == 0){
                continue;
            }
            else{
                return false;
            }
        }
        
        return true;
    }

    int countArrangement(int n) {
        vector<int> nums(n);
        for(int i = 1; i <= n; i++){
            nums[i - 1] = i;
        }

        vector<vector<int>> permutations;
        permutations = kev(nums);

        int count = 0;
        for(auto perm : permutations){
            if(rev(perm)){
                count++;
            }
        }

        return count;
    }
};


class Solution {
// take the permuation alg and modify it , i was so stupid.
public:
    int ans = 0;
    bool kev(int ind,vector<int> a){
        if(ind >= a.size()){
            ans ++;
            return 1;
        }
        for(int i = ind; i < a.size(); i++){
            if (a[i] % (ind + 1) == 0 || (ind + 1) % a[i] == 0){
                swap(a[ind], a[i]);
                kev(ind+1, a);
                swap(a[ind], a[i]);
            }
        }

        return true;
    }

    int countArrangement(int n) {
        vector<int> nums(n);
        for(int i = 1; i <= n; i++){
            nums[i - 1] = i;
        }

        kev(0, nums);

        return ans;
    }
};
