class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return std::distance(nums.begin(),remove(nums.begin(),nums.end(),val));
    }
};
