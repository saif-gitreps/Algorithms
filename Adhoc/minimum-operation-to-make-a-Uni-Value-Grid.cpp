
class Solution {
public:
    int minOperations(vector<vector<int>>& a, int x) {
        vector<int> nums;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[0].size(); j++) {
                nums.push_back(a[i][j]);
            }
        }

        sort(nums.begin(), nums.end());
        int n = nums.size(), median, ans = 0;
        
        // if (n / 2 == 1) {
        //     median = nums[n/2];
        // } else {
        //     int num1 = nums[n/2 - 1];
        //     int num2 = nums[n/2];
        //     median = (num1 + num2) / 2;
        // }
        median = nums[n/2];
        
        for (int i = 0; i < n; i++) {
            int z = abs(nums[i] - median);
            if (z % x != 0) {
                return -1;
            }
            ans += (z / x);
        }
        return ans;
    }
};
