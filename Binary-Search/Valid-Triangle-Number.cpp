class Solution {
// bruteforce , TLE at last few cases.
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0 ;
        if(nums.size() < 3){
            return 0;
        }
        for(int i = 0; i < nums.size() -2 ; i++){
            for(int j = i + 1 ; j < nums.size() - 1; j++){
                for(int k = j + 1; k < nums.size(); k++){
                    if( nums[i] < nums[j] + nums[k] &&
                        nums[j] < nums[i] + nums[k] &&
                        nums[k] < nums[i] + nums[j]){
                        count ++;
                    }
                }
            }
        }
    return count;
    }
};
