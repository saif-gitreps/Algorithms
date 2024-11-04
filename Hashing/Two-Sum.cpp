class Solution {
// naive solution
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> a;
        
        for (int i = 0; i < nums.size(); i++) {
            a.push_back({
                nums[i],
                i
            });
        }

        sort(a.begin(), a.end());

        int L = 0, R = nums.size() - 1;

        while (L != R) {
            if (a[L].first + a[R].first == target) {
                return {
                    a[L].second,
                    a[R].second
                };
            } else if (a[L].first + a[R].first < target) {
                L++;
            } else {
                R--;
            }
        }

        return { -1 };
    }
};

class Solution {
// we know that Target = nums[1] - nums[i], so we use that logic to do a single by pass with a map.
// which also helps us to find the other number without needing to sort or do two loops.
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            if (!mp.count(target - nums[i])) {
                mp[nums[i]] = i;
            } else {
                return {
                    i,
                    mp[target - nums[i]]
                };
            }
        }

        return { -1 };
    }
};
