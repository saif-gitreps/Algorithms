class Solution {
// this one worked till 12/21 cases.
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0; 
        int sum = 0;
        int mn = INT_MAX;
        for(int j = 0 ; j < nums.size(); j++){
            sum += nums[j];
            if(sum > target){
                while(sum > target){
                    sum -= nums[i];
                    i++;
                }
            }
            if(sum == target){
                mn = min(mn, (j - i + 1));
                sum -= nums[i];
                ++i;
            }
        }
        return mn == INT_MAX ? 0 : mn;
    }
};


class Solution {
// This one is a bit tweaked and it worked, if u have confusion about the first test case not being
// 1 and is 2, then remember j becomes 5 after getting j++, and 5 - 3 is 2. 
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0; 
        int sum = 0;
        int mn = INT_MAX;
        for(int j = 0 ; j < nums.size(); ){
            sum += nums[j++];
            if(sum >= target){
                while(sum >= target){
                    mn = min(mn, (j - i));
                    sum -= nums[i++];
                }
            }
        }
        return mn == INT_MAX ? 0 : mn;
    }
};
