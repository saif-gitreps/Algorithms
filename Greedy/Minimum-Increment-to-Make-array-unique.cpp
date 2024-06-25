class Solution {
// First naive attempt, showerd TLE surprisingly. 
public:
    int minIncrementForUnique(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto num : nums){
            mp[num]++;
        }
        
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] > 1){
                int num = nums[i];
                while(mp.count(num)){
                    num++;
                    count++;
                }
                mp[nums[i]]--;
                mp[num] = 1;
            }
        }

        return count;
    }
};


class Solution {
// for a sorted array {1, 1, 2, 2, 3, 7} 
// it goes like {1 , 2, 2, 2, 3 , 7}
// {1 , 2 , 3, 2, 3, 7} -> {1, 2 , 3 , 4, 3 , 7} -> {1, 2, 3, 4, 5, 7}
// now the count is the increment we had to do throughtout the iteration. 
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] >= nums[i]){
                count += ((nums[i - 1] - nums[i]) + 1);
                nums[i] += ((nums[i - 1] - nums[i]) + 1);
            }
        }

        return count;
    }
};

// Solved again after 1 week 4 days.
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] >= nums[i]){
                long long diff = (nums[i - 1] - nums[i]) + 1; 
                nums[i] += diff;
                count += diff;
            } 
        }

        return count;
    }
};
