class Solution {
// Naive bruteforce, TLE 
public:
    int largestRectangleArea(vector<int>& h) {
        int mx = 0;
        for(int i = 0 ; i < h.size(); i++){
            int left = i - 1;
            int right = i + 1;
            while(left >= 0 && h[left] >= h[i]){
                left--;
            }
            while(right < h.size() && h[right] >= h[i]){
                right++;
            }
            left++;
            right--;
            int height = (right - left + 1) * h[i];
            mx = max(height, mx);
        }
        return mx;
    }
};
