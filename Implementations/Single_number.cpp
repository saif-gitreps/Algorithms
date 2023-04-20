class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   for(auto x:nums)
	   ans^=x;
	   return ans;
    }
}
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i = 1 ;i < nums.size() ; i += 2){
            if(nums[i]!=nums[i-1]){
                return nums[i-1];
            }
        }
        return nums[nums.size()-1];
    }
};
//1) xor of a same number with itself is zero, i.e A ^ A = 0
//2) xor is commutative that means a ^ b = b ^ a.
//3) xor of any number with zero is the number itself i.e A ^ 0 = A
