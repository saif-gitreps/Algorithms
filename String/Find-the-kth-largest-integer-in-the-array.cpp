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



bool compare(string a , string b){
    if(a.size() < b.size()){
        return true;
    }
    else{
        return false;
    }
}
class Solution {
// much better result, we first sort it in terms of order.
// then we sort it in terms of size. 
// worked till  180/210 cases.
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end());
        sort(nums.begin(), nums.end(), compare);
        return nums[nums.size() - k];      
    }
};
