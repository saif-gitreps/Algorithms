class Solution {
// bruteforce attempt. TLE.
public:
    void kev(int i, vector<int> temp, vector<int> &nums, vector<int> &ans){
        if(i == nums.size()){
            for(auto num : temp){
                for(auto n : temp){
                    if(num != n &&  num % n != 0 && n % num != 0){
                        return;
                    }
                }
            }
            if(temp.size() > ans.size()){
                ans = temp;
            }
            return;
        }   

        temp.push_back(nums[i]);
        kev(i + 1, temp, nums, ans);
        
        temp.pop_back();
        kev(i + 1, temp, nums, ans);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        vector<int> temp;
        
        kev(0, temp, nums, ans);

        return ans;
    }
};
