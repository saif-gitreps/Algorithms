class Solution {
  // i mean its suspicious that it works , we neeed to find a better way.
public:
    bool search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
            return true;
        }
    return false;}
};
