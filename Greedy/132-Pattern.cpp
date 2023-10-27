class Solution {
// i understood the intuition , this attempt worked for 73/110 cases.
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3){
            return false;
        }
        int mn = nums[0];
        int max_found = false;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > mn){
                max_found = true;
                mn = nums[i];
            }
            else if(max_found && mn > nums[i]){
                return true;
            }
        }
        return false;
    }
};

class Solution {
// solution with mono tonic stack, we store the elements and the minimum that was found.
// so we are storing 2 variables at the same time. if we find a current element
// that is smaller than the element at top(the max element since this is a invserve sorted stack),
// And then we check if the minimum element found is also smaller than the current element at the iteration, then we can return true.

public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3){
            return false;
        }
        int mn = nums[0];
        stack<pair<int,int>> s;
        //Mono tonic stack is like sorted stack. 
        for(int i =  1; i < nums.size(); i++){
            while(s.size() >= 1 && s.top().first <= nums[i]){
                s.pop();
            }
            if(s.size() >= 1 && nums[i] < s.top().first && nums[i] > s.top().second){
                return true;
            }
            s.push({nums[i], mn});
            mn = min(mn, nums[i]);
        }
        return false;
    }
};
