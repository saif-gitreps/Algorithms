class Solution {
// Bruteforce works, time to memoize.
public:
    int kev(int n, int s1, int s2, vector<int> a){
        if(n == 0){
            if(s1 + a[n] == s2 || s2 + a[n] == s1){
                return 1;
            }
            return 0;
        }
        int s1_pick = 0;
        int s2_pick = 0;
        s1_pick = kev(n-1, s1+a[n], s2, a);
        s2_pick = kev(n-1, s1, s2+a[n], a);
        return s1_pick || s2_pick;
    }
    bool canPartition(vector<int>& nums) {
        return kev(nums.size()-1, 0, 0, nums);
    }
};

class Solution {
// shows TLE after 41 cases. using 3D array shows memory limit exceeding.
public:
    int kev(int n, int s1, int s2, vector<int> a, vector<map<pair<int,int>,int>> &dp){
        if(n == 0){
            if(s1 + a[n] == s2 || s2 + a[n] == s1){
                return 1;
            }
            return 0;
        }
        pair<int, int> p1 = {s1, s2};
        if (dp[n].find(p1) != dp[n].end()) {
            return dp[n][p1];
        }
        int s1_pick = 0;
        int s2_pick = 0;
        s1_pick = kev(n-1, s1+a[n], s2, a, dp);
        s2_pick = kev(n-1, s1, s2+a[n], a, dp);
        return dp[n][p1] = s1_pick || s2_pick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<map<pair<int,int>,int>> dp(n);  
        return kev(n-1, 0, 0, nums, dp);
    }
};

class Solution {
// this worked for 68 and then TLE, this was the best attempt at bottom up.
// The part and trick i missed waas that, we only need to find the half of the sum.
// What i mean by that i dont need to run two variable and equat them at some point of time.
// just take the half and run a loop to find that half, edge case is if there is odd then theres no way
// to evenly make a partition.
public:
    int kev(int n, int sum, vector<int> a, vector<vector<int>> &dp){
        if(sum < 0 ){
            return 0;
        }
        if(n == 0){
            if(sum - a[n] == 0 || sum == 0){
                return dp[n][sum] = 1;
            }
            return 0;
        }
        if(sum == 0){
            return dp[n][sum] = 1;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        int pick = 0;
        int not_pick = 0;
        pick = kev(n-1, sum-a[n], a, dp);
        not_pick = kev(n-1, sum, a, dp);
        return dp[n][sum] = pick || not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto x : nums){
            total += x;
        }
        if(total % 2 != 0){
            return false;
        }
        vector<vector<int>> dp(n, vector<int> (total, -1));   
        return kev(n-1, total/2, nums, dp);
    }
};

class Solution {
// top-down is so hard ffs.
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto x : nums){
            total += x;
        }
        if(total % 2 != 0){
            return false;
        }
        vector<vector<int>> dp(n, vector<int> ((total/2) + 1, 0));   
        
        for(int i = 0; i < n; i++){
            //from any index if i get 0 then it is true , this loop is for that.
            dp[i][0] = true;
        }
        if(nums[0] <= (total/2)){
            dp[0][nums[0]] = true;
        }
        for(int i = 1; i < n; i++){
            for(int j = total/2; j >= 1; j--){
                int pick = 0;
                int not_pick = 0;
                if(j >= nums[i]){
                    pick = dp[i-1][j-nums[i]];
                }
                not_pick = dp[i-1][j];
                dp[i][j] = pick || not_pick;
            }            
        }
        return dp[n-1][(total/2)];
    }
};

