class Solution {
// this attempt from problem 1 did 190/193.
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mn = INT_MAX; 
        while(left <= right){
            int mid = left + (right - left) / 2;
            mn = min(mn, nums[mid]);
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            mn = min(mn, nums[mid]);
            if(nums[mid] >= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return mn;
    }
};
