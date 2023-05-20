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

class Solution {
  // with this algorithm , part of it works , now add i-- at the end of the if case , and part of other test
  // cases works and some dont. so i dont know to balance it as of now.
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int limit = n-1,dup = 0;
        for(int i=0;i+2<n;i++){
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                dup++;
                nums.push_back(0);
                limit++;
                int k = i;
                while(k+1<limit){
                    swap(nums[k],nums[k+1]);
                    k++;
                }
            }
        }
        return n-dup;
    }
};

class Solution {
  // works till 20th test case , cant work frm test case to test cse , need to see editoirla
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return n;
        }
        int limit = n-1,dup = 0;
        for(int i=0;i+2<n;i++){
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                dup++;
                nums.push_back(0);
                limit++;
                int k = i;
                while(k+1<limit){
                    swap(nums[k],nums[k+1]);
                    k++;
                }
                i--;
            }
        }
        if(n-dup<2){
            return (n-dup)+1;
        }
        return n-dup;
    }
};
