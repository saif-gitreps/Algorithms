class Solution {
public:
    // explanation: 
    https://youtu.be/21XhR6r5jU8?si=IOOeH-cFWAwFkYhD
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) {
            return 0;
        }
        int mx = 0;
        int n = nums.size();

        int minValue = INT_MAX;
        int maxValue = INT_MIN;

        for(auto num : nums){
            minValue = min(num, minValue);
            maxValue = max(num, maxValue);
        }

        int bucketSize = (int)ceil( (double) (maxValue - minValue) / (n-1) );

        vector<int> minBucket(n - 1, INT_MAX);
        vector<int> maxBucket(n - 1, INT_MIN);

        for(int i = 0 ; i < n ; i++){
            if(nums[i] != minValue && nums[i] != maxValue){
                int bucketIndex = (nums[i] - minValue) / bucketSize;

                minBucket[bucketIndex] = min(nums[i], minBucket[bucketIndex]);
                maxBucket[bucketIndex] = max(nums[i], maxBucket[bucketIndex]);
            }
        }

        for(int i = 0 ; i < n - 1; i ++){
            if(maxBucket[i] == INT_MIN){
                continue;
            }
            mx = max(minBucket[i] - minValue, mx);
            minValue = maxBucket[i];
        }

        return maxValue - minValue > mx ? maxValue - minValue : mx;
    }
};
