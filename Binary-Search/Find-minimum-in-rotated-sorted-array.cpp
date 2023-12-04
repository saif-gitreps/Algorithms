class Solution {
// i would say it was a good attempt.
public:
    int findMin(vector<int>& nums) {
        int mn = nums[0];
        int left = 0;
        int right = nums.size()-1;
        while(left < right){
            int mid = (left + right) / 2;
            mn = min(mn, nums[mid]);
            if(mid-1 >=0 && mid+1 < nums.size() && nums[mid-1] < nums[mid] && nums[mid] <= nums[mid+1]){
                left = mid + 1;
            }
            else if(mid-1 >=0 && mid+1 < nums.size() && nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }
        }
        return mn;
    }
};
