class Solution {
// I knew this algorithm from before.
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int mx = -10001;
        int sum = -10001;
        for(int i = 0 ; i < nums.size(); i ++){
            if( sum + nums[i] >= nums[i]){
                sum += nums[i];
            }
            else{
                sum = nums[i];
            }
            mx = max(sum, mx);
        }
        return mx;
    }
};
