
// so this is a class related/unsusal problem , this codes passes 5/8 testcases. 
class Solution {
public:

    Solution(vector<int>& num) {
        this->nums = num;
        copy = num;
    }
    vector<int> reset() {
        return copy;
    }
    
    vector<int> shuffle() {
        int temp = this->nums[0];
        for(int i=1;i<this->nums.size();i++){
            this->nums[i-1] = this->nums[i];
        }
        this->nums[this->nums.size()-1] = temp;
        return this->nums;
    }
private:
    vector<int> nums;
    vector<int> copy;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

//==========================================================================//
