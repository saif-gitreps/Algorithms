class Solution {
    // attempt 1;
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid,left =0,right = nums.size()-1;
        while(left<right){
            mid = left + (right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        left = 0;right = nums.size()-1;
        mid = left + (right-left)/2;
        if(target<nums[mid]){
            right = mid-1;
            if(target<=nums[left]){
                return 0;
            }
            else if(target>=nums[right]){
                return right;
            }
            while(mid!=1){
                if()
            }

        }
        else{
            left = mid+1;
            if(target<=nums[left]){
                return left;
            }
            else if(target>=nums[right]){
                return right;
            }
        }

           
    }
};

class Solution {
    // ok so my critical error was i didnt analize left and right index, i only
    // analized mid , i should have checked on paper where my left lands, so the trick was 
    // where left lands if ther element was not found , that was to be thee expected index .
    // but this alg , only passes  30/63 test cases.
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid,left =0,right = nums.size()-1;
        while(left<right){
            mid = left + (right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return left+1;

           
    }
};

class Solution {
    // made the condition even more specific, works now til 42 test cases.
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid,left =0,right = nums.size()-1;
        while(left<right){
            mid = left + (right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        if(target>nums[left]){
            return left+1;
        }
        else if(target<nums[0]){
            return 0;
        }
        else{
            return left+2;
        }  
    }
};