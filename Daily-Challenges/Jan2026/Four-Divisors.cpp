class Solution {
public:
    int find_all(int num) {
        int r = floor(sqrt(num));
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;

        for (int i = 1; i <= r; i++) {
            if (num % i == 0) {
                if (mp.find(i) == mp.end()) {
                    count++;
                    sum += i;
                    mp[i] = 1;
                } 
                if (mp.find(num/i) == mp.end()) {
                    count++;
                    sum += (num/i);
                    mp[num/i];
                }
            }

            if (count > 4) {
                return -1;
            }
        }

        return count == 4 ? sum : -1;
    }
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int result = -1;
            if (mp.find(nums[i]) == mp.end()) {
                result = find_all(nums[i]);
                mp[nums[i]] = result;
            } else {
                result = mp[nums[i]];
            }

            if (result != -1) {
                sum += result;
            }
        }

        return sum;
    }
};
