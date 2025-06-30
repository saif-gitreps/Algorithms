class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int left = 0 ; 
        int right = a.size()-1;
        while(left < right){
            if(a[left] + a[right] == target){
                return {left+1 , right+1};
            }
            else if(a[left] + a[right] < target){
                left++;
            }
            else{
                right--;
            }
        }
        return {-1,-1};
    }
};
