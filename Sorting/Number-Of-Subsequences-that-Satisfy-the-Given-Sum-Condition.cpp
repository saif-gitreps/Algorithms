class Solution {
// WEll on the theory it was supposed to work but idk why i am geting neg value for one case.
public:
    int mod_exp(int base, int exp, int mod) {
        int result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * 1LL * base) % mod;
            }
            base = (base * 1LL * base) % mod;
            exp /= 2;
        }
        return result;
    }
    int numSubseq(vector<int>& nums, int target) {
        int i = 0, j = 0, curr_sum = 0,count = 0, mod = 1e9 + 7;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int L = i, R = nums.size() - 1;
            if (nums[L] * 2 > target) break;
            
            while (L <= R) {
                int mid = L + (R - L) / 2;

                if (nums[mid] + nums[i] > target) {
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            
            }

            int dist = R - i + 1;
            long long a = (long long)pow(2, dist) % mod, b = (long long)pow(2, dist - 1) % mod;
             count += ((a - b));
        }

        return count;
    }
};
