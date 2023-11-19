class Solution {
// one of the attempt , passed 147/163
public:
    int kev(int n, int sum, vector<int> a, vector<vector<int>> &dp){
        if(n < 0){
            return 0;
        }
        if(sum == 0){
            return dp[n][sum] = 1;
        }
        if(n == 0){
            if(sum == a[n]){
                return dp[n][sum] = 1;
            }
            return dp[n][sum] = 0;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        int pick = 0;
        int not_pick = 0;
        if(sum >= a[n]){
            pick = kev(n-1 , sum - a[n], a, dp);
        }
        not_pick = kev(n-1, sum, a, dp);
        return dp[n][sum] = pick + not_pick;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i ++){
            sum += nums[i];
        }
        if(sum % k != 0){
            return false;
        }
        vector<vector<int>> dp(n, vector<int> ((sum/k)+1, -1));
        int ans = kev(n-1 , sum/k, nums, dp);
        
        return ans >= k ? true : false;
    }
};


class Solution {
// working solution, so here what our intuition is:
// First we check if we can take the sum of the array and divide it by K, and does it give us reminder 0 or no.
// If it does then we may or may not be able to divide the array into K groups with equal sums.
// Our recursion will start from 0... N and throughout the traversal it will pick up sum, if our sum == total_sum/k 
// then we wil go back to the first index but this time , the elements that were picked in the previous recurison that gave the result
// will be hashed so they wont be allowed to be picked again.
public:
    bool kev(int i, int k,int sum, int target,vector<int> &a, vector<int> &dp){
        if(i >= a.size()) {
            return false;
        }
        if(k == 1){
            return true;
        }
        if(sum == target){
            return kev(0, k-1, 0, target, a, dp);
        }
        for(int j = i; j < a.size(); j++){
            if(dp[j] == 1 || sum + a[j] > target){
                continue;
            }
            dp[j] = 1;
            if(kev(j + 1, k, sum + a[j], target, a, dp)) {
                return true;          
            }
            dp[j] = -1;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i ++){
            sum += nums[i];
        }
        if(sum%k != 0 || n < k) {
            return false;
        }
        vector<int> dp(n, -1);
        return kev(0 , k, 0, sum/k, nums, dp);
        
    }
};
