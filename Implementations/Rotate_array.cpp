class Solution {
  // naive solution , shows TLE.
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        while(k--){
            int temp = nums[n-1];
            for(int i=n-1;i>0;i--){
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
        }
    }
};
