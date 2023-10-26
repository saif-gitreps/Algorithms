class Solution {
// i understood the intuition , this attempt worked for 73/110 cases.
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3){
            return false;
        }
        int mn = nums[0];
        int max_found = false;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > mn){
                max_found = true;
                mn = nums[i];
            }
            else if(max_found && mn > nums[i]){
                return true;
            }
        }
        return false;
    }
};
