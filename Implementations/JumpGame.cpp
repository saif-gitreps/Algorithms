class Solution {
public:
    bool canJump(vector<int>& nums) {
      int reachable =0 ; int n = nums.size();
      for(int i=0;i<n;i++){
          if(reachable<i){
              return false;
          }
          reachable = max(reachable,nums[i]+i);
      }
      return true;
    }
};

// we first get the maximum index we can traverse with an array value
// if we were to come accross such indexes where it seemed that we cannot go further,
// then the i value increases more than reachable value then we know we are stuck. else true.
