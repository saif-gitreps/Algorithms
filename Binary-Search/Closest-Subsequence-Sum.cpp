class Solution 
{
// bruteforce.
public:
    map<pair<int, int> , int> dp;
    int kev(int i, int sum, int goal, vector<int> &a){
        if(i > a.size()){
            return INT_MAX;
        }

        if(i == a.size()){
            return abs(sum - goal);
        }

        if(dp.count({i, sum})){
            return dp[{i, sum}];
        }

        int pick = kev(i + 1, sum + a[i], goal, a);
        int not_pick = kev(i + 1, sum , goal, a);

        return dp[{i, sum}] = min(pick, not_pick);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        return kev(0, 0, goal, nums);
    }
};

class Solution {
// First we divide the array,
// we do a pick not pick on this and take all the potential sums from two halves of the array.
// We sort any one of the array.
// so what we are trying to do is we take a sum (from bruteforcce of one half) of s1
// we minus it with goal, goal - s1[i] . then we try to find the lowerbound or the largest value
// that is equal to smaller than (goal - s1[i]). and we take the min of minus of all three (goal - s1[i] - LBound).
// its like large scale bruteforce but broken down into smaller steps.
 public:
    void kev(int i, int n, int sum, vector<int> &a, vector<int> &res){
        if(i == n){
            res.push_back(sum);
            return;
        }
        kev(i + 1, n, sum + a[i], a, res);
        kev(i + 1, n, sum , a, res);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int> s1;
        vector<int> s2;
        int n = nums.size();
        
        kev(0, n / 2, 0, nums, s1);
        kev(n / 2, n, 0, nums, s2);

        sort(s2.begin(), s2.end());
        int ans = INT_MAX;
        for(int i = 0; i < s1.size(); i ++){
            auto it = lower_bound(s2.begin(), s2.end(), goal - s1[i]);
            if(it != s2.end()){
                ans = min(ans, abs(goal - *it - s1[i]));
            }
            if(it != s2.begin()){
                ans = min(ans, abs(goal - *(--it) - s1[i]));
            }
        }
        return ans;
    }
};
