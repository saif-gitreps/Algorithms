class Solution {
// solid attempt after hint 1, 81/84.
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long, long long> mp;
        for(int i = 0 ; i < nums.size(); i++){
            int rev = 0;
            int temp = nums[i];
            while(temp > 0){
                rev = rev * 10 + (temp % 10);
                temp /= 10;
            }
            mp[nums[i] - rev] ++;
        }
        int ans = 0;
        for(auto s : mp){
            ans += (s.second * ( s.second - 1) / 2);
        }
        return ans;
    }
};
