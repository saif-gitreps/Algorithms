class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};


class Solution {
// O(n) solution.
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int left = 0 ; int right = nums.size()-1;
        int ptr = right;
        while(left<=right){
            if(abs(nums[right])>=abs(nums[left])){
                ans[ptr--] = nums[right] * nums[right];
                right--;  
            }
            else if(abs(nums[right])<abs(nums[left])){
                ans[ptr--] = nums[left] * nums[left];
                left++;
            }
        }
        return ans;
    }
};
