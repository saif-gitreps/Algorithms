class Solution {
// Passed 1065/1068 cases. And... TLE 
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0 ; i < nums.size() ; i ++){
            mp[nums[i]].push_back(i);
        }
        vector<long long> ans;
        for(int i = 0 ; i < nums.size() ; i ++){
            if(mp[nums[i]].size() == 1){
                ans.push_back(0); continue;
            }
            long long num = 0;
            for(auto j : mp[nums[i]]){
                if( j != i){
                    num += abs(i - j);
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};
