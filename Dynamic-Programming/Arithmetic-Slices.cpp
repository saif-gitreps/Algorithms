// do a dry run on 1 2 3 4.
class Solution {
public:
    int kev(vector<int> nums){
        int count = 0;

        int diff;

        for(int i = 0; i < nums.size() - 2; i ++){
            diff = nums[i + 1] - nums[i];

            for(int j = i + 2; j < nums.size(); j++){
                if(nums[j] - nums[j - 1] == diff){
                    count ++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3){
            return 0;
        }
        return kev(nums);
    }
};

class Solution {
// do another dry run
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size(); // extracting the size of the array
        
        if(n < 3)  // if size is less than 3
        {
            return 0; // then simply return 0
        }
        
        int ans = 0, curr = 0; // declaring variables
        
        // for the first part
        // it stores what is the difference of last consecutive elements
        int last_diff = arr[1] - arr[0];
        
        // start traversing from the array
        for(int i = 1; i < n - 1; i++)
        {
            // for any index what is the current difference
            int curr_diff = arr[i + 1] - arr[i];
            
            // if current difference is equal to the last difference
            if(curr_diff == last_diff)
            {
                curr++; // increase current variable
            }
            else // but if not, give current difference to last difference
            {
                last_diff = curr_diff;
                curr = 0; // and make curr to zero, as we have to do a new start
            }
            
            ans = ans + curr; // add current to our answer
        }
        
        return ans; // finally return the answer
    }
};
