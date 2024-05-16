class Solution {
// Bruteforce , pointer to the first and pointer to the end.
// keep comparing until you dissimilarity between the sorted and original array.
// return the famouse forumula of length distance J - I + 1.
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());

        int i, j;
        for(i = 0; i < nums.size() && nums[i] == temp[i]; i++);
        for(j = nums.size() - 1; j >= 0 && nums[j] == temp[j]; j--);

        if(i < j) {
            return j - i + 1;
        }
        else{
            return 0;
        }
    }
};
