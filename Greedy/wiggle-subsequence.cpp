class Solution {
// Idk had some idea in my mind wasnt working.
public:
    int wiggleMaxLength(vector<int>& nums) {
        int prev = 10005;
        int count = 1;
        int mx = -1;
        for(int i = 0 ; i+1 < nums.size(); i++){
            if(i == 0){
                prev =  nums[i + 1] - nums[i];
                count++;
                mx = max(mx, count);
            }
            else{
                int sum = nums[i + 1] - nums[i];
                if(prev < 0 && sum >= 0){
                    count++;
                    prev = sum;
                    mx = max(mx, count);
                }
                else if(prev >= 0 && sum < 0){
                    count++;
                    prev = sum;
                    mx = max(mx, count);
                }
                else{
                    mx = max(mx, count);
                    count = 0;
                    prev = sum;
                }
            }
        }
        return mx;
    }
};
