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

class Solution {
// neetcode's algorithm
public:
    int firstMissingPositive(vector<int>& nums) {
        // intuition 4: we convert our current array to a hashmap.
        // One loop to set hash for 1...nums.size()+1.
        // Then second loop to find them missing. 
        int small = 1;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] < 0){
                nums[i] = 0;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            // mind that we already eliminated negative numbers.
            // this absolute is for duplicates.
            int num = abs(nums[i]);
            // now we check if we got a number from 1...N.
            if( num >=1 && num <= nums.size() ){
                // now in that index of that number we set it negative.
                if(nums[num - 1] > 0){
                    nums[num - 1] *= -1;
                }
                else if(nums[num-1] == 0){
                    nums[num - 1] = (nums.size()) * -1;
                }
            }
        }
        for(int i = 1; i <= nums.size(); i++){
            // Our goal was to check if values 1...N were present at the array.
            // These 1...N were stored as 1-1...N-1.
            // Now at their designated i-1 index if the values not negative then that means that small value is missing.
            if(nums[i - 1] >= 0){
                return i;
            }
        }
        return nums.size()+1;
    }
};
