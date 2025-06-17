class Solution {
// almost close, mistake was to update boundaries and not adjacent element.
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long mx = 0;

        for (auto n: nums) {
            long long curr = mp[n];
            if (mp.find(n) != mp.end() && mp[n] > 1) {
                continue;
            }
            if (mp.find(n-1) != mp.end()) {
                curr += mp[n-1];
            }
            if (mp.find(n+1) != mp.end()) {
                curr += mp[n+1];
            }

            curr += 1;
            mp[n] = curr;
             
            if (mp.find(n-1) != mp.end()) {
                mp[n-1] = curr;
            }
            
            if (mp.find(n+1) != mp.end()) {
                mp[n+1] = curr;
            }

            // debug(n);
            // debug(mp[n]);
            // debug(mp[n-1]);
            // debug(mp[n+1]);
            // debug("----");

            mx = max(curr, mx);
        }

        return mx;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mx = 0;

        for (int n : nums) {
            if (mp.count(n)) continue;

            int left = mp.count(n - 1) ? mp[n - 1] : 0;
            int right = mp.count(n + 1) ? mp[n + 1] : 0;
            int length = left + right + 1;

            // Update current number's length
            mp[n] = length;

            // Update the boundary lengths
            if (left) 
                mp[n - left] = length;
            if (right)
                mp[n + right] = length;

            mx = max(mx, length);
        }

        return mx;
    }
};
