class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected = (nums.size()+1)*((nums.size()+1)-1)/2;
        int sum = 0 ; 
        for(int i = 0 ;i < nums.size(); i++){
            sum += nums[i];
        }
        return expected-sum;     
    }
};
