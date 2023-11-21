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
