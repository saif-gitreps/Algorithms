// do a dry run on 1 2 3 4.
class Solution {
public:
    int kev(vector<int> nums){
        int count = 0;

        int diff;

        for(int i = 0; i < nums.size() - 2; i ++){
            diff = nums[i + 1] - nums[i];

            for(int j = i + 2; j < nums.size(); j++){
                if(nums[j] - nums[j - 1] == diff){
                    count ++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3){
            return 0;
        }
        return kev(nums);
    }
};
