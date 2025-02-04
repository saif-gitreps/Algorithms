// interesting easy problem
// naive attempt.
class Solution {
public:
    bool is_sorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) {
                return false;
            }
        }
        return true;
    }
    
    void rotate(vector<int>& nums) {
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i-1] = nums[i];
        }
        nums[nums.size()-1] = temp;
    }

    bool check(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (is_sorted(nums)) {
                return true;
            } else {
                rotate(nums);
            }
        }
        return false;
    }
};

class Solution {
// idea behind this is that, if the array was rotated any number of times, there will always be 
// one case of a number[i-1] greater than number[i]. 
// the last if check is for the case where, nums[last] is greater than first element.
public:
    bool check(vector<int>& nums) {
        int impurity = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) {
                impurity++;
            }

            if (impurity > 1) {
                return false;
            }
        }

        if (impurity >= 1 && nums[nums.size()-1] > nums[0]) {
            return false;
        }

        return true;
    }
};

// using mod

    public boolean check(int[] A) {
        int k = 0, n = A.length;
        for (int i = 0; i < n; ++i) {
            if (A[i] > A[(i + 1) % n]) {
                k++;
            }
            if (k > 1) {
                return false;
            }
        }
        return true;
    }
