class Solution {
// first attempt, my concept was totally off.
public:
    unsigned long long factorial(unsigned int n) {
        if (n == 0 || n == 1) {
            return 1; 
        }
        unsigned long long result = 1;
        for (unsigned int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int count = 0;
        int seq = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] >= left && nums[i] <= right){
                if(i == nums.size()-1){
                    count += factorial(seq + 1);
                }
                seq++;
            }
            else{
                if(seq == 0){
                    continue;
                }
                count += factorial(seq);
                seq = 0;
            }
        }
        // if(seq > 0){
        //     count += factorial(seq);
        // }
        return count;
    }
};
