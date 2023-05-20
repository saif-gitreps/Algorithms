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
