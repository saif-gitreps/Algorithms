class Solution {
// not accepted
// would work if all the unique elements are unique
public:
    int repeatedNTimes(vector<int>& nums) {
        int num = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != num) {
                return nums[i];
            }
            num++;
        }

        return -1;
    }
};

class Solution {
// there will always be a case where [x,x,y,z] or [x,y,z,x] or [x,y,x,z] for n = 3
public:
    int repeatedNTimes(vector<int>& nums) {
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i-2] == nums[i] || nums[i-1] == nums[i]) {
                return nums[i];
            }
        }

        return nums[0];
    }
};
