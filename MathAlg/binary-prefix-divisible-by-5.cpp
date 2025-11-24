class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size(), false);
        long long num = 0;
        int n = nums.size()-1;
        for (int i = nums.size()-1; i >= 0; i--) {
            num += nums[i] * pow(2,n - i);
        }

        int i = n;
        while (num || i >= 0) {
            if (num % 5 == 0) {
                ans[i] = true;
            } 
            num /= 2;
            i--;
        }

        return ans;
    }
};
