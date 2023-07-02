class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return std::distance(nums.begin(),remove(nums.begin(),nums.end(),val));
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count =0;
        if(nums.size()==0){
            return 0;
        }
        for(int i=0;i<nums.size();){
            bool check = false;
            if(nums[i]==val){
                count++;
                int temp = nums[i];
                int j;
                for(j=i;j<nums.size()-1;j++){
                    nums[j] = nums[j+1];
                }
                nums[nums.size()-1] = temp;
                nums.pop_back();
                check = true;
            }
            else{
                i++;
            }
            if(check){
                i=0;
            }
        }
        if(nums[0]==val && nums.size()==1){
            nums.pop_back();
            return 0;
        }
        return nums.size();
    }
};
