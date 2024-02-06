class Solution {
// had similar beginngin intuition in mind, missed a few intuition later on.
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int right = 0;
        int left = 0 , mid;
        for(auto w : weights){
            right += w;
            left = max(left, w);
        }
        int mn = INT_MAX;
        while(left <= right){
            mid = (left + right) / 2;
            int count = 0;
            int temp = 0;
            for(auto w : weights){
                if(temp - w < 0){
                    count++;
                    temp = mid;
                }
                temp -= w;
            }
            if(count <= days){
                mn = min(mn, mid);
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return mn;
    }
};
