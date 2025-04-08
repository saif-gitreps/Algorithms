class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i += 3) {
            unordered_set<int> s;
            bool is_unique = true;
            for (int j = i; j < nums.size(); j++) {
                if (s.find(nums[j]) != s.end()) {
                    is_unique = false;
                    count++;
                    break;
                } else {
                    s.insert(nums[j]);
                }
            }
            if (is_unique) {
                return count;
            }
        }
        return count;
    }
};
