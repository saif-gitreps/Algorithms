class Solution {
// TC -> O(n long n) , SC -> O(1). Need tc of O(N).
public:
    int firstMissingPositive(vector<int>& nums) {
        // intuition 1: if the largest element is equal to or -1 or +1 less than the size , then use the sum formula and -= the sum of the array, ignoring the negative numbers.
        // intuition 2: we try to figure out something for the edge case.
        sort(nums.begin(),nums.end());
        int small = 1;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] < 0){
                continue;
            }
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }
            if(small == nums[i]){
                small++;
            }
        }
        return small;
    }
};
