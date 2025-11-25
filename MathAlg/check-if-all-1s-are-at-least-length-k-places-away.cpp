class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (last_index == -1 && nums[i] == 1) {
                last_index = i;
            } else if (nums[i] == 1) {
                int d = i - last_index;
                d--;
                if (d < k) return false;
                last_index = i;
            }
        }
        return true;
    }
};
