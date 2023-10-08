class Solution {
// bruteforce , TLE at last few cases.
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0 ;
        if(nums.size() < 3){
            return 0;
        }
        for(int i = 0; i < nums.size() -2 ; i++){
            for(int j = i + 1 ; j < nums.size() - 1; j++){
                for(int k = j + 1; k < nums.size(); k++){
                    if( nums[i] < nums[j] + nums[k] &&
                        nums[j] < nums[i] + nums[k] &&
                        nums[k] < nums[i] + nums[j]){
                        count ++;
                    }
                }
            }
        }
    return count;
    }
};

class Solution {
// two pointer sorting ,on the principle that in a sorted array , a b c , if a+b> c , then no need to check a+c or b+c .
// using this idea we can do 2 pointer .
// sorting Nlog N, loop , TC -> O(n^2 log N).
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3){
            return 0;
        }
        int count = 0;
        sort(nums.begin(),nums.end());
        // i >= 2 because i want to go till third first element from the back.
        for(int i = nums.size()-1 ; i >= 2; i--){
            int left = 0;
            int right = i - 1;
            while(left < right){
                if(nums[left] + nums[right] > nums[i]){
                    count += (right - left);
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return count;
    }
};
