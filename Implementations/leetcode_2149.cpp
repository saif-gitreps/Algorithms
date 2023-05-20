// PROBLEM:  Rearrange Array Elements by Sign

class Solution {
  // first attempt. worked but , it is the slowest and the solution with the hgihest space complexity.
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int neg=0,pos=0,sign=1;
        vector<int> negative;
        vector<int> positive;
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                negative.push_back(nums[i]);
            }
            else{
                positive.push_back(nums[i]);
            }
        }
        while(neg<negative.size() && pos<positive.size()){
            if(sign%2==1){
                a.push_back(positive[pos++]);
            }
            else{
                a.push_back(negative[neg++]);
            }
            sign++;
        }
        if(neg<negative.size()){
            a.push_back(negative[neg++]);
        }
        if(pos<positive.size()){
            a.push_back(positive[pos++]);
        }
        return a;
    }
};

class Solution {
  // understood this solution . this is the best in terms of time space complexity.
  // in here every position for positive and negative is fixed, so it doesnt matter if 
  // in the original array we have -4,-7,-7. since the space is left for each negative and positive. 
  // all the consecutive negative nubers in the ogirinal arrays will be placed after an interval of 2.
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int neg=1,pos=0;
        vector<int> a(nums.size());
        for(auto x: nums){
            if(x<0){
                a[neg] = x;
                neg += 2;
            }
            else{
                a[pos] = x;
                pos += 2;
            }
        }
        return a;
    }
};
