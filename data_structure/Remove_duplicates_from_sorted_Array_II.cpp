class Solution {
  // first attempt, shows TLE for some reason. 
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int limit = n-1,dup = 0;
        for(int i=0;i+2<n;i++){
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                dup++;
                int k = i+2;
                while(k+1<n){
                    swap(nums[k],nums[k+1]);
                    k++;
                }
                i--;
            }

        }
        return n-dup;
    }
};
class Solution {
  // worked till 9th test case, then showed TLE.
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int limit = n-1,dup = 0;
        for(int i=0;i+2<n;i++){
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                dup++;
                int k = i;
                while(k+1<n){
                    swap(nums[k],nums[k+1]);
                    k++;
                }
                if(i+3<n){
                    i--;
                }
            }

        }
        return n-dup;
    }
};
