class Solution {
public:
    int findMinDifference(vector<string>& a) {
        vector<int> nums;

        for (int i = 0;i < a.size(); i++) {
            int hour = stoi(a[i].substr(0, 2));
            int mins = stoi(a[i].substr(3));

            int num = hour * 60 + mins;
            nums.push_back(num);    
        }

        sort(nums.begin(), nums.end());
        int ans = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            int diff = abs(nums[i-1] - nums[i]);
            ans = min(diff, ans);
        }

        ans = min(ans, abs((1440 - nums.back()) + nums[0])); 

        return ans;
    }
};
