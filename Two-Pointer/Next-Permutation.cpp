class Solution {
//I gave my best try, worked till 178/266 till I hit a logic error,
//theoretically next perm of 2,3,1 should be 3, 2, 1 
//but I don't know why it says the correct answer is 3, 1, 2.
public:
    void nextPermutation(vector<int>& nums) {
      // my logic was we will check for the fist case if it is DESC completely then we return reverse,
        bool desc = true;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] < nums[i]){
                desc = false; 
                break;
            }
        }
        if(desc){
            reverse(nums.begin(), nums.end());
            return;
        }
      // else from the last element we will try to find the element is smaller than ith element.
      // then we will shift everything telse from that jth index to the end and in that jth index put ith num.
        for(int i = nums.size() - 1; i >= 0; i--){
            bool nex = false;
            int num = nums[i];
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    for(int k = i; k-1 >= 0 && k-1 >= j; k--){
                        nums[k] = nums[k - 1];
                    }
                    // i am replacing the num after shifting.
                    nums[j] = num;
                    nex = true;
                    break;
                }
            }
            if(nex){
                break;
            }
        }
    }
};

class Solution {
// 132 <- dry run this on paper and see
public:
    void nextPermutation(vector<int>& nums) {
        int bp = -1;
        for(int i = nums.size() - 1; i >= 1; i--){
            if(nums[i - 1] < nums[i]){
                bp = i - 1;
                break;
            }
        }
        if(bp == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = nums.size() - 1; i > bp; i--){
            if(nums[i] > nums[bp]){
                swap(nums[i], nums[bp]);
                break;
            }
        }
        reverse(nums.begin() + bp + 1, nums.end());
        return;
    }
};
