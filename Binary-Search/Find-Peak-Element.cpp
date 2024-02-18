class Solution {
// very weird question have to come back to this oneday.
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[n - 1] > nums[n - 2]){
            return n - 1;
        }
        int left = 1;
        int right = n - 2;

        while(left <= right){
            int mid = (left + right) / 2;
            if(mid - 1 >= nums[mid - 1] && mid + 1 < n && nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]){
                return mid;
            }
            else if(mid - 1 >= 0 && nums[mid - 1] < nums[mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left - 1;        
    }
};
