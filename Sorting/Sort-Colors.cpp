class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_0 = 0, count_1 = 0, count_2 = 0;
        for (auto num : nums) {
            if (num == 0) count_0++;
            if (num == 1) count_1++;
            if (num == 2) count_2++; 
        }

        int i = 0;
        while(count_0--) nums[i++] = 0;
        while(count_1--) nums[i++] = 1;
        while(count_2--) nums[i++] = 2;
    }
};
