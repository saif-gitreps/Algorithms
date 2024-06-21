class Solution {
/*
nitialization:

miss: Tracks the smallest sum that cannot currently be formed. Initialize miss to 1 since initially, we cannot form the number 1.
added: Counter for the number of patches added to nums. Initialize to 0.
i: Index to iterate over elements in nums. Initialize to 0.
Iterative Process:

While miss is less than or equal to n:
If i is within bounds of nums and nums[i] is less than or equal to miss, it means nums[i] can help form the number miss. Hence, add nums[i] to miss and move to the next element in nums by incrementing i.
If nums[i] is greater than miss or i is out of bounds, it means we cannot form the number miss with the current elements in nums. Therefore, add miss itself as a patch to extend the range of constructible sums. Update miss to miss + miss and increment the added counter.
Conclusion:

The loop terminates when miss exceeds n, ensuring that all numbers up to n can be formed.
The variable added will hold the minimum number of patches required.
*/
public:
    int minPatches(vector<int>& nums, int n) {
        long long count = 0,i = 0, min_sum = 1;

        while(min_sum <= n){
            if(i < nums.size() && nums[i] <= min_sum){
                min_sum += nums[i];
                i++;
            } else{
                min_sum += min_sum;
                count++;
            }
        }

        return count;
    }
};
