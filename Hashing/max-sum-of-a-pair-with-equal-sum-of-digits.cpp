class Solution {
// yay was able to solve it.
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp;

        for (auto num : nums) {
            int sum = 0;
            int temp = num;
            while (temp) {
                sum += (temp % 10);
                temp /= 10;
            }
            if (mp.find(sum) == mp.end()) {
                mp[sum].first = num;
                mp[sum].second = -1;
            } else {
                if (mp[sum].first <= num) {
                    mp[sum].second = mp[sum].first;
                    mp[sum].first = num;
                } else if (mp[sum].second <= num) {
                    mp[sum].second = num;
                }
            }
        }
        int ans = -1;
        for (auto it : mp) {
            if (it.second.second != -1)
                ans = max(ans, it.second.first + it.second.second);
        }
        return ans;
    }
};

// more improved version. i could just do the second right in the same loop right after the else case,

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp;
        int ans = -1;

        for (auto num : nums) {
            int sum = 0;
            int temp = num;
            while (temp) {
                sum += (temp % 10);
                temp /= 10;
            }
            if (mp.find(sum) == mp.end()) {
                mp[sum].first = num;
                mp[sum].second = -1;
            } else {
                if (mp[sum].first <= num) {
                    mp[sum].second = mp[sum].first;
                    mp[sum].first = num;
                } else if (mp[sum].second <= num) {
                    mp[sum].second = num;
                }
                ans = max(ans, mp[sum].first + mp[sum].second);
            }
        }
        return ans;
    }
};
