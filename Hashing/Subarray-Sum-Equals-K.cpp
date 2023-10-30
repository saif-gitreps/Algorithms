class Solution {
// this was a dp attempt , although this is apparently prefix sum and greedy solution.
public:
    int kev(int n, int sum, vector<int> &a, int k, vector<int> &dp){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            if(sum + a[n] == k){
                return 1;
            }
            return 0;
        }
        if(sum == k){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int pick = 0;
        int not_pick = 0; 
        pick = kev(n-1, sum+a[n], a, k, dp);
        not_pick = kev(n-1, sum, a, k, dp);
        return dp[n] = pick + not_pick;
    }
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return kev(n-1, 0, nums, k, dp);
    }
};


class Solution {
/*
    understood what it meant, we are storing all the prefix sums in a hashmap.
    and at each iteration we take the prefixsum , then at that iteration we -= k.
    When we -= k , we check if that resultant leads to an existing prefix in the map (if it doesn't then its 0 by default).
    Then we store or increment the prefix in hashmap.
*/
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            prefix += nums[i];
            count += mp[prefix - k];
            mp[prefix] += 1;
        }
        return count;        
    }
};
