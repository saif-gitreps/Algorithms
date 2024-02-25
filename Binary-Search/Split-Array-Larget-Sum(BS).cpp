class Solution {
public:
    int kev(int i, int k, vector<int> &a){
        int left = 0, right = 0;
        
        for(auto n : a){
            left = max(left, n);
            right += n;
        } 

        int ans = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int count = 1;
            int sum = 0;
            
            for(auto n : a){
                sum += n;
                if(sum > mid){
                    count++;
                    sum = n;
                }
            }
            
            if(count > k){
                left = mid + 1;
            }
            else{
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }   
    int splitArray(vector<int>& nums, int k) {
        return kev(0, k, nums);
    }
};
