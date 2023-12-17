bool compare(string a, string b){
    return stoi(a) < stoi(b);
}
class Solution {
//Naive attempt, the problem is nums[i].size() is in the range or 0 to 100.
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), compare);
        return nums[nums.size() - k];      
    }
};
