https://leetcode.com/problems/minimize-maximum-of-array/
class Solution {
// adhoc type problem . tricky problem.
public:
    int minimizeArrayValue(vector<int>& nums) {
        int res = nums[0];
        double avg = 0;
        for(int i = 0 ; i < nums.size(); i ++){
            avg += nums[i];
            res = max(res, (int)ceil(avg/(i+1)));
        }
        return res;
    }
};
