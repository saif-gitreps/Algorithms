class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    // apparently O(n) is more slower than the frist one. 
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]>=2){
                return true;
            }
        }
        return false;
    }
};
