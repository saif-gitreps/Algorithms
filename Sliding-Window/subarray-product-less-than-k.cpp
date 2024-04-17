class Solution {
// naive, int overflow.
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            long long sum = 1;
            for(int j = i; j < nums.size(); j++){
                sum *= nums[j];
                if(sum < k){
                    count ++;
                }
            }
        }
        return count;
    }
};

class Solution {
// we will keep one pointer i and another j, we will take the product from j till we get a large number.
// then we will start shifting the i pointer (left pointer) , while we are shifting , we will exclude the product 
// of the left pointers. (j - i + 1) is a typical formula used in sliding window.
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0, res = 1;
        for(int i = 0,j = 0; j < nums.size(); j++){
            res *= nums[j];

            while(res >= k && i <= j){
                res /= nums[i];
                i++;
            }
            count += (j - i + 1);
        }
        return count;
    }
};
