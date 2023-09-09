class Solution {
public:
// lets get the obvious solution out of the way.
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size() - k];   
    }
};
