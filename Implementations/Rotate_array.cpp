class Solution {
  // naive solution , shows TLE for large input.
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        while(k--){
            int temp = nums[n-1];
            for(int i=n-1;i>0;i--){
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
        }
    }
};
class Solution1 {
public:
 // this method first we reverse entire array 
 // egs:- {1,2,3,4,5} -> {5,4,3,2,1}
 // then we rotate first k arrays -> let k = 2 {3,4,5,2,1};
 // the we unroater from k till end -> {3,4,5,1,2};
 // it seems that k%n is the magic behind it ,i dont seem to understand.
 // For example, let's say we have an array of size 5 and we want to rotate it 
 // 7 positions to the right. If we use k = 7, 
 // the resulting array would be the same as if we had rotated it 2 
 // positions to the right, since 7 is equivalent to 
 // 2 when taken modulo 5 (i.e., 7 % 5 = 2).

// So, in general, k % n ensures that k is always a value between 0 and n-1 (inclusive), 
// where n is the size of the array. This is useful because rotating an array by n positions results in the original array, 
  
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

class Genius_Solution {
public:
  // i+k%n would go from lets say k= 0 in an array of 7 to -> 3,4,5,6,0,1,2
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> ans(n);
      
        for(int i=0; i<n; i++)
        ans[(i+k)%n] = nums[i];
        nums=ans;
    }
};
