class Solution {
// first attempt, kind of works for 50cases/560 cases.
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<int> copy_array = nums;
        sort(copy_array.begin(),copy_array.end());
        //unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            int left = 0;int right = nums.size()-1;
            int mid;
            while(left < right){
                mid = left + (right-left)/2;
                if(copy_array[mid] == nums[i]){
                    ans += abs(mid - i);
                    break;
                }
                else if(copy_array[mid] < nums[i]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return ans + nums.size();
    }
};
