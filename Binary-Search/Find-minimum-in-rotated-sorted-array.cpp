class Solution {
// i would say it was a good attempt.
// update : adding a break, made it pass 87/150 cases.
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
            else{
                break;
            }
        }
        return mn;
    }
};


class Solution {
// wait i ll get back to u with the explanation.
// So, we just have to find which half of the array our mid is on, ex, 3,4,5,1,2 <- 345 is one half.
// we can either compare the left most element or right most element.
// If our right most element is smaller than mid element , then we know we are at the first half, and we have
// to move to other half. and while traversing we just compute min element along with it.
// Our goal here is to find the transition line in the rotated array.
public:
    int findMin(vector<int>& nums) {
        int mn = nums[0];
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = (left + right) / 2;
            mn = min(mn, nums[mid]);
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return mn;
    }
};
