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


bool compare(string a , string b){
    if(a.size() == b.size()){
        if(a < b){
            return true;
        }
        else{
            return false;
        }
    }
    else if(a.size() < b.size()){
        return true;
    }
    else{
        return false;
    }
}
class Solution {
// YAY , it worked, the hint helped me.
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), compare);
        //sort(nums.begin(), nums.end());
        return nums[nums.size() - k];      
    }
};



class Solution {
// an example using MAX HEAP.
public:
    struct compare{
        bool operator()(string &a , string &b){
            if(a.size() == b.size()){
                for(int i = 0; i < a.size(); i++){
                    if(a[i] - '0' > b[i] - '0'){
                        return true;
                    }
                    else if(a[i] - '0' < b[i] - '0'){
                        return false;
                    }
                }
                return false;
            }
            else if(a.size() > b.size()){
                return true;
            }
            else{
                return false;
            }
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        priority_queue<string, vector<string> , compare> q;
        for(auto x : nums){
            q.push(x);
            if(q.size() > k){
                q.pop();
            }
        }
        return q.top();    
    }
};
