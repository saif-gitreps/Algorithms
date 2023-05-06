class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i =0 ; i<nums.size();i++){
            if(nums[i]!=0){
                continue;
            }
            for(int j = i+1;j<nums.size();j++){
                if(nums[j]!=0 && nums[i]==0){
                    swap(nums[i],nums[j]);
                }
            }
        }
    }
};

class Solution {
public:
    /*
    tthis is the proper solution , it beats 98% in memory but is the last in time complexity.
    */
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==NULL){
            return;
        }
        for(int i =0 ; i<nums.size();i++){
            if(nums[i]!=0){
                continue;
            }
            for(int j = i+1;j<nums.size();j++){
                if(nums[j]!=0 && nums[i]==0){
                    swap(nums[i],nums[j]);
                }
            }
        }
    }
};

class Solution3 {
    //linear solution.
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==NULL){
            return; 
        }
        int j = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};
