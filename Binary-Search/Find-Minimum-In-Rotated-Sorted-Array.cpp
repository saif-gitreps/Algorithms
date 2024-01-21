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


class Solution {
// YAAAAAAASSSSSSSSSSSSS , solved it on my own yay
// intuition was, if we encounter similar numbers on either left or right
// Then we trim both sides. and continue our BS search.
// TC -> O(n) for Worst case. 
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mn = INT_MAX; 
        while(left <= right){
            int mid = left + (right - left) / 2;
            mn = min(mn, nums[mid]);
            if(nums[left] == nums[right]){
                mn = min(nums[left], mn);
                left++; right--;
            }            
            else if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return mn;
    }
};
