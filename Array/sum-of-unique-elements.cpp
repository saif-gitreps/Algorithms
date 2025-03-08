class Solution {
// easy
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> mp(101, 0);
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] == 1) sum += nums[i]; 
        }
        return sum;
    }
};

class Solution {
// clever one loop solution.
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> mp(101, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (++mp[nums[i]] == 1) {
                sum += nums[i];
            } else if (mp[nums[i]] == 2){
                sum -= nums[i];
            }
        }
        return sum;
    }
};
