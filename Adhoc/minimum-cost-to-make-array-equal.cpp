class Solution {
// https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/

//so it worked till 8/42 test cases ,which i am surprised since this is a hard problem. 
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        double avg = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            avg += nums[i];
        }
        long long ceil_val = (long long)ceil(avg/nums.size());
        long long floor_val = (long long)floor(avg/nums.size());
        long long min_cost_ceil = 0;
        long long min_cost_floor = 0;
        for(int i = 0 ; i < nums.size(); i++){
            // if(nums[i] == ceil_val || nums[i] == floor_val){
            //     continue;
            // }
            long long val1 = abs(nums[i]-ceil_val) * cost[i];
            long long val2 = abs(nums[i]-floor_val ) * cost[i];

            min_cost_ceil += val1;
            min_cost_floor += val2; 
        }
        return min(min_cost_ceil,min_cost_floor);
    }
};
