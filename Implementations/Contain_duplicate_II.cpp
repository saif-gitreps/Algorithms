class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> selected;
        for(int i=0;i<nums.size();i++){
            if(selected.count(nums[i])){
                if(abs(selected[nums[i]]-i)<=k){
                    return true;
                }
            }
            selected[nums[i]] = i;
        }
        return false;
    }
};