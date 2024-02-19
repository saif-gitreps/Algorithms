class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = -1;

        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            int rem = total % k;
            if(!mp.count(rem)){
                mp[rem] = i;
            }
            else if(i - mp[rem] > 1){
                return true;
            }
        }
        return false;
    }
};
