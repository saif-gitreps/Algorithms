// Search in Rotated Sorted Array
class Solution {
  // have to study this code again, watch https://www.youtube.com/watch?v=oTfPJKGEHcc&ab_channel=Techdose for indept details.
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
   int left = 0;
   int right = n-1;
   int mid;
   while(left<=right){
      mid = left + (right-left)/2;
      if(nums[mid]==target){
         return mid;
      }
      else if(nums[mid]>=nums[left]){
         if(target<=nums[mid] && target>=nums[left]){
            right = mid-1;
         }
         else{
            left = mid+1;
         }
      }
      else{
         if(target>=nums[mid] && target<=nums[right]){
            left = mid+1;
         }
         else{
            right = mid-1;
         }

      }
   }
      return -1;
    }
};

class Solution {
public:
  // this time i understood the algorithmn , so i had to resubmit.
    int search(vector<int>& nums, int target) {
        int n = nums.size();
  int left = 0;
  int right = n-1;
  int mid;
  while(left<=right){
   mid = left + (right-left)/2;
   //step1 , check which part is uniform half
   if(nums[mid]==target){
      return mid;
   }
   else if(nums[left]<=nums[mid]){
      if(target>=nums[left] && target<=nums[mid]){
         right = mid-1;
      }
      else{
         left = mid+1;
      }
   }
   else{
      if(target>=nums[mid] && target<=nums[right]){
         left = mid+1;
      }
      else{
         right = mid-1;
      }
   }
  }
  return -1;
    }
};
