//
class Solution {
public:
    // naive appraoch i guess?
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1), suf(n, 1);
        pref[0] = (nums[0]);
        suf[n-1] = (nums[n-1]);
        
        for (int i = 1; i < nums.size(); i++) {
            pref[i] = pref[i-1] * nums[i]; 
        }
        for (int i = n-2; i >= 0; i--) {
            suf[i] = suf[i+1] * nums[i]; 
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int LEFT;
            int RIGHT;
            if (i > 0 && i + 1 < nums.size()) {
                LEFT = pref[i-1];
                RIGHT = suf[i+1];
                ans.push_back(LEFT * RIGHT);
            } else if (i == 0) {
                ans.push_back(suf[1]);
            } else if (i + 1 == n) {
                ans.push_back(pref[n-2]);
            }
        }

        return ans;
    }
};
