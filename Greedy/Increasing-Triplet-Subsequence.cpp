class Solution {
// This one worked til 67/83 cases ,and i ran into an edge case.
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3){
            return false;
        }
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++){
            if(pq.empty() == true){
                pq.push(nums[i]);
            }
            if(nums[i] > pq.top()){
                pq.push(nums[i]);
            }
        }
        return pq.size() >= 3;
    }
};


class Solution {
// Three pointer idea, even this is stuck at that same test case,
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3){
            return false;
        }
        int slow = nums[0];
        int fast = nums[1];
        int haste = nums[2];
        for(int i = 3 ; i < nums.size(); i++){
            if((slow < fast && slow < haste) && (fast < haste)){
                return true;
            }
            if(nums[i] >= haste){
                haste = nums[i];
            }
            if(nums[i-1] >= fast && nums[i-1] < haste){
                fast = nums[i-1];
            }
            if(nums[i-2] >= slow && nums[i-2] < haste && nums[i-2]< fast){
                slow = nums[i-2];
            }
        }
        if((slow < fast && slow < haste) && (fast < haste)){
            return true;
        }
        else{
            return false;
        }
    }
};
