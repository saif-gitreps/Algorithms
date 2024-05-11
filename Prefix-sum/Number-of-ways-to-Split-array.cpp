class Solution {
// Ok this was easy Prefix problem, nothing to brag about.
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long prefs[n];
        prefs[0] = nums[0];

        for (int i = 1; i < n; i++){
            prefs[i] = prefs[i - 1] + nums[i];
        }

        long long ans = 0, last = prefs[n - 1];
        for (int i = 0; i < n - 1; i++){
            long long diff = last - prefs[i];
            if (prefs[i] >= diff) {
                ans ++;
            }
        }

        return ans;
    }
};
